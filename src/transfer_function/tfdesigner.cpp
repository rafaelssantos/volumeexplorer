#include "tfdesigner.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
#include <set>
#include <cuda_runtime.h>
#include "tfmanager.cuh"
#include "settings/tfsettings.h"
#include "transfer_function/pivot.h"



using namespace dimensionality_reduction;
using namespace std;
using namespace settings;
using namespace transfer_function;
using namespace volume;




TFDesigner& TFDesigner::instance() {
	static TFDesigner instance;

	return instance;
}




void TFDesigner::execDimReduction(const Volume& volume, vector<vector<float>* >& data, float normalizationRange) {
	free();

	vector<vector<float>>* normalizedData = normalize(data, normalizationRange, volume);

	m_dimReducedData = m_fastmapAlgorithm.exec(volume, *normalizedData, 2);
	restoreDefaultColor(volume);

	delete normalizedData;
}





void TFDesigner::exeClustering(const Volume& volume, float eps, int minPoints, float normalizationRange) {
	eps = eps * normalizationRange;

	delete m_clusters;
	m_clusters = m_dbscanAlgorithm.exec(volume, *m_dimReducedData, eps, minPoints);

	delete m_voxelsPerCluster;
	m_voxelsPerCluster = new map<int, set<int>>();


	for(auto i = 0; i < m_clusters->size(); i++) {
		(*m_voxelsPerCluster)[m_clusters->at(i)].insert(i);
	}
}




void TFDesigner::execSimilarySearch(float alpha) {
	delete m_pivotsPerCluster;

	m_pivotsPerCluster = new map<int, set<int>>();

	set<int>* pivots = nullptr;


	for(auto entry = m_voxelsPerCluster->begin(); entry != m_voxelsPerCluster->end(); entry++){
		pivots = m_sssAlgorithm.exec(*m_dimReducedData, entry->second, alpha);

		(*m_pivotsPerCluster)[entry->first] = *pivots;
		delete  pivots;
	}
}





vector<vector<float>>* TFDesigner::normalize(vector<vector<float>*>& data, float range, const Volume& volume) {
	vector<float> max(data.size());
	vector<float> min(data.size());

	for(int a = 0; a < data.size(); a++){
		max[a] = numeric_limits<float>::min();
		min[a] = numeric_limits<float>::max();
		for(auto i = 0; i < data[a]->size(); i++) {
			if(data[a]->at(i) > max[a]){
				max[a] = data[a]->at(i);
			}
			if(data[a]->at(i) < min[a]){
				min[a] = data[a]->at(i);
			}
		}
	}

    vector<vector<float>>* normalized = new vector<vector<float>>(data.size());

	for(auto a = 0; a < data.size(); a++){
		float delta = (max[a] - min[a]);
		for(auto i = 0; i < data[a]->size(); i++) {
            normalized->at(a).emplace_back((data[a]->at(i) / delta) * range);
		}
	}


    return normalized;
}



void TFDesigner::restoreDefaultColor(const Volume& volume) {
	for(auto x = 0; x < m_hostTransferFunc->dim().x; x++) {
		for(auto y = 0; y < m_hostTransferFunc->dim().y; y++) {
			for(auto z = 0; z < m_hostTransferFunc->dim().z; z++) {
				uchar4 color;
				color.x = color.y = color.z = color.w = static_cast<unsigned char>(volume.sampleAt(x, y, z));
				m_hostTransferFunc->setSampleAt(x, y, z, color);
			}
		}
	}

	TransferFunctionManager::instance().memcpyColors(m_hostTransferFunc, m_devTransferFunc);
}






float2 TFDesigner::dimReducedDataAt(int index) const {
	float2 instance;

	instance.x = m_dimReducedData->front().at(index);
	instance.y = m_dimReducedData->back().at(index);

	return instance;
}





void TFDesigner::buildLookUpTable() {
	delete m_lookUpTable;
	m_lookUpTable = new LookUpTable(m_hostTransferFunc);

	for(auto c = m_voxelsPerCluster->begin(); c != m_voxelsPerCluster->end(); c++){
		Cluster* cluster = new Cluster();
		cluster->setIndex(m_clusters->size());
		m_lookUpTable->m_clusters.emplace_back(cluster);

		for(auto p = m_pivotsPerCluster->at(c->first).begin(); p != m_pivotsPerCluster->at(c->first).end(); p++){
			Pivot* pivot = new Pivot();

			pivot->setUI(new PivotUI(m_lookUpTable->m_pivots.size(), dimReducedDataAt(*p)));
			pivot->setCluster(cluster);
			pivot->voxelIndices()->emplace_back(*p);

			cluster->pivots()->emplace_back(pivot);
			m_lookUpTable->m_pivots.emplace_back(pivot);
		}

		for(auto v = c->second.begin(); v != c->second.end(); v++){
			Pivot* pivot = cluster->pivots()->front();
			float minDist = m_sssAlgorithm.euclideanDist(*m_dimReducedData, *v, pivot->voxelIndices()->front());

			for(auto p = cluster->pivots()->begin(); p != cluster->pivots()->end(); p++){
				float dist = m_sssAlgorithm.euclideanDist(*m_dimReducedData, *v, (*p)->voxelIndices()->front());
				if(dist < minDist){
					pivot = *p;
					minDist = dist;
				}
			}
			pivot->voxelIndices()->emplace_back(*v);
		}
	}
}




void TFDesigner::free() {
	delete m_dimReducedData;
	m_dimReducedData = nullptr;

	delete m_clusters;
	m_clusters = nullptr;

	delete  m_voxelsPerCluster;
	m_voxelsPerCluster = nullptr;

	delete m_pivotsPerCluster;
	m_pivotsPerCluster = nullptr;

	delete m_lookUpTable;
	m_lookUpTable = nullptr;
}




void TFDesigner::freeUI() {
	if(m_lookUpTable != nullptr){
		for(auto p = m_lookUpTable->m_pivots.begin(); p != m_lookUpTable->m_pivots.end(); p++){
			delete (*p)->ui();
		}
	}
}



bool TFDesigner::isDimReduced() const {
	return m_dimReducedData != nullptr;
}




bool TFDesigner::isClustered() const {
	return m_clusters != nullptr;
}




bool TFDesigner::isSimilaritySearched() const {
	return m_pivotsPerCluster != nullptr;
}




void TFDesigner::setSelectedCluster(int index) {
	m_lookUpTable->setSelectedCluster(index, TFSettings::instance().selectedOpacity(), TFSettings::instance().unselectedOpacity());

	TransferFunctionManager::instance().memcpyColors(m_hostTransferFunc, m_devTransferFunc);
}




void TFDesigner::setSelectedGroup(int index) {
	m_lookUpTable->setSelectedGroup(index, TFSettings::instance().selectedOpacity(), TFSettings::instance().unselectedOpacity());

	TransferFunctionManager::instance().memcpyColors(m_hostTransferFunc, m_devTransferFunc);
}




void TFDesigner::setSelected(SelectionMode selectionMode, bool selected, int pivotIndex) {
	if(selected) {
		m_lookUpTable->setSelectedAt(selectionMode, pivotIndex, TFSettings::instance().selectedOpacity(), TFSettings::instance().unselectedOpacity());
	}
	else{
		m_lookUpTable->setUnselectedAt(selectionMode, pivotIndex, TFSettings::instance().unselectedOpacity());
	}

	TransferFunctionManager::instance().memcpyColors(m_hostTransferFunc, m_devTransferFunc);
}




void TFDesigner::setSelectedPivot(int index) {
	m_lookUpTable->setSelectedPivot(index, TFSettings::instance().selectedOpacity(), TFSettings::instance().unselectedOpacity());

	TransferFunctionManager::instance().memcpyColors(m_hostTransferFunc, m_devTransferFunc);
}




void TFDesigner::unselectAll() {
	m_lookUpTable->unselectAll();

	TransferFunctionManager::instance().memcpyColors(m_hostTransferFunc, m_devTransferFunc);
}




void TFDesigner::group() {
	m_lookUpTable->groupSelectedPivots();
}



void TFDesigner::ungroup() {
	m_lookUpTable->ungroupSelectedPivots();
}




size_t TFDesigner::clusterCount() const {
	return m_lookUpTable->m_clusters.size();
}





size_t TFDesigner::groupCount() const {
	return m_lookUpTable->m_groups.size();
}




size_t TFDesigner::pivotCount() const {
	return m_lookUpTable->m_pivots.size();
}




void TFDesigner::setVoxelColor(int index, const float4 &color) {
	uchar4 byteColor;

	byteColor.w = static_cast<unsigned char>(color.w * 255.0f);
	byteColor.x = static_cast<unsigned char>(color.x * 255.0f);
	byteColor.y = static_cast<unsigned char>(color.y * 255.0f);
	byteColor.z = static_cast<unsigned char>(color.z * 255.0f);

	m_hostTransferFunc->setSampleAt(m_hostTransferFunc->indexToIndex3(index), byteColor);
}




void TFDesigner::setPivotColor(int index, const float4& color) {
	m_lookUpTable->setPivotColor(index, color);

	TransferFunctionManager::instance().memcpyColors(m_hostTransferFunc, m_devTransferFunc);
}




void TFDesigner::setClusterColor(int index, const float4& color) {
	m_lookUpTable->setClusterColor(index, color);

	TransferFunctionManager::instance().memcpyColors(m_hostTransferFunc, m_devTransferFunc);
}



void TFDesigner::setSelectedColor(const float4& color) {
	m_lookUpTable->setSelectedPivotsColor(color);

	TransferFunctionManager::instance().memcpyColors(m_hostTransferFunc, m_devTransferFunc);
}



void TFDesigner::setTransferFunction(TransferFunction* hostTransferFunc, TransferFunction* devTransferFunc) {
	m_hostTransferFunc = hostTransferFunc;
	m_devTransferFunc = devTransferFunc;
}






const vector<Pivot*>* TFDesigner::pivots() const {
	if(m_lookUpTable != nullptr){
		return &(m_lookUpTable->m_pivots);
	}
	else{
		return nullptr;
	}
}




TFDesigner::TFDesigner() {
	m_dimReducedData = nullptr;
	m_clusters = nullptr;

	m_voxelsPerCluster = nullptr;
	m_pivotsPerCluster = nullptr;
	m_lookUpTable = nullptr;

	m_hostTransferFunc = nullptr;
	m_devTransferFunc = nullptr;
}




TFDesigner::~TFDesigner() {
	free();
}
