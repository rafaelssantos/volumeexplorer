#ifndef TFDESIGNER_H
#define TFDESIGNER_H


#include <map>
#include <set>
#include <string>
#include <vector>
#include "clustering/dbscan.h"
#include "dimensionality_reduction/fastmap.h"
#include "lookuptable.h"
#include "pivot.h"
#include "similarity_search/sparsespatialselection.h"
#include "volume/volume.cuh"



namespace transfer_function {
	class TFDesigner {
		public:
			static TFDesigner& instance();

			void execDimReduction(const volume::Volume& volume, std::vector<std::vector<float>*>& data, float normalizationRange = 1000000.0f);

			void exeClustering(const volume::Volume& volume, float eps, int minPoints, float normalizationRange = 1000000.0f);

			void execSimilarySearch(float alpha);

			void buildLookUpTable();

			void free();

			void freeUI();

			bool isDimReduced() const;

			bool isClustered() const;

			bool isSimilaritySearched() const;

			void setSelectedCluster(int index);

			void setSelectedGroup(int index);

			void setSelected(SelectionMode selectionMode, bool selected, int pivotIndex);

			void setSelectedPivot(int index);

			void unselectAll();

			void group();

			void ungroup();

			size_t clusterCount() const;

			size_t groupCount() const;

			size_t pivotCount() const;

			void setVoxelColor(int index, const float4& color);

			void setPivotColor(int index, const float4& color);

			void setClusterColor(int index, const float4& color);

			const std::vector<Pivot*>* pivots() const;

			void setSelectedColor(const float4& color);

			void setTransferFunction(transfer_function::TransferFunction* hostTransferFunc, transfer_function::TransferFunction* devTransferFunc);

			void restoreDefaultColor(const volume::Volume& volume);


		private:
			TFDesigner();

			virtual ~TFDesigner();

			float2 dimReducedDataAt(int index) const;

            std::vector<std::vector<float> >* normalize(std::vector<std::vector<float>*>& data, float range, const volume::Volume& volume);

			dimensionality_reduction::FastMap m_fastmapAlgorithm;

			similarity_search::SparseSpatialSelection m_sssAlgorithm;

			clustering::DBSCAN m_dbscanAlgorithm;

			TransferFunction* m_hostTransferFunc;

			TransferFunction* m_devTransferFunc;

			std::vector<std::vector<float>>* m_dimReducedData;

			std::vector<int>* m_clusters;

			LookUpTable* m_lookUpTable;

			std::map<int, std::set<int>> *m_voxelsPerCluster;

            std::map<int, std::set<int>> *m_pivotsPerCluster;
	};
}



#endif // TFDESIGNER_H
