#include "dbscan.h"

#include "log_utils/logger.h"
#include <limits>
#include <cmath>


using namespace log_utils;
using namespace std;
using namespace clustering;




DBSCAN::DBSCAN() {

}




DBSCAN::~DBSCAN() {

}





vector<int>* DBSCAN::exec(const volume::Volume &volume, const std::vector<std::vector<float> >& data, float eps, int minPts) {
	DBSCANGrid* grid = nullptr;
	vector<int> *clusterIndices = nullptr;

    grid = new DBSCANGrid(volume, data, eps);

	determineCorePoints(*grid, minPts, eps);

	clusterIndices = new vector<int>(volume.voxelCount(), -1);

	mergeClusters(*grid, eps, clusterIndices);

	determineBorderPoints(*grid, minPts, eps, clusterIndices);

	for(auto i = 0u; i < volume.voxelCount(); i++){
		if(clusterIndices->at(i) == -1){
			clusterIndices->at(i) = 0;
		}
	}

	delete grid;
	grid = nullptr;


	return clusterIndices;
}





void DBSCAN::determineCorePoints(const DBSCANGrid& grid, int minPts, float eps) const {
	for(auto entry = grid.cellsSparseMatrix().begin(); entry != grid.cellsSparseMatrix().end(); entry++) {
		Cell *cell = entry->second;

		if(cell->points()->size() >= minPts) {
			cell->setCore(true);

			for(auto p = cell->points()->begin(); p != cell->points()->end(); p++) {
				p->setCore(true);
			}
		}
		else{
			for(auto p = cell->points()->begin(); p != cell->points()->end(); p++) {
				if(hasMoreThanMinPts(grid,*cell, *p, minPts, eps)) {
					p->setCore(true);
					cell->setCore(true);
				}
			}
		}
	}
}





bool DBSCAN::hasMoreThanMinPts(const DBSCANGrid& grid, const Cell& cell, const DBSCANPoint& point, int minPts, float eps) const {
	int2 center = grid.posToInt2Index(point.x(), point.y());
	int2 begin  = {center.x - 2, center.y - 2};
	int2 end    = {center.x + 2, center.y + 2};
	int neighborPointCount = cell.points()->size();

	float eps2 = eps * eps;

	for(auto x = begin.x; x <= end.x; x++) {
		for(auto y = begin.y; y <= end.y; y++) {
			if(x == begin.x && (y == begin.y || y == end.y)) {
				continue;
			}
			else if(x == end.x && (y == begin.y || y == end.y)) {
				continue;
			}
			else if(x == center.x && y == center.y) {
				continue;
			}
			else{
				const Cell* neighborCell = grid.cellAt(x, y);

				if (neighborCell != nullptr) {
					for (auto p = neighborCell->points()->begin(); p != neighborCell->points()->end(); p++) {
						if(euclideanDist2(point, *p) <= eps2) {
							neighborPointCount++;
							if(neighborPointCount >= minPts) {
								return true;
							}
						}
					}
				}
			}
		}
	}

	return neighborPointCount >= minPts;
}




void DBSCAN::mergeClusters(const DBSCANGrid& grid, float eps, std::vector<int>* clusters) const {
	set<int> visitedCells;

	int clusterCount = 1;

	for(auto entry = grid.cellsSparseMatrix().begin(); entry != grid.cellsSparseMatrix().end(); entry++) {
		if(entry->second->isCore() && visitedCells.find(entry->first) == visitedCells.end()) {
			mergeClustersDFS(grid, eps, entry->first, clusterCount, &visitedCells, clusters);
			clusterCount++;
		}
	}
}




void DBSCAN::mergeClustersDFS(const DBSCANGrid& grid, float eps, int cellIndex, int clusterIndex, std::set<int> *visitedCells, std::vector<int>* clusterIndices) const {
	visitedCells->insert(cellIndex);
	vector<DBSCANPoint*> points;

	Cell *cell = grid.cellAt(cellIndex);

	for(auto p = cell->points()->begin(); p != cell->points()->end(); p++) {
		if(p->isCore()) {
			clusterIndices->at(p->index()) = clusterIndex;
			points.emplace_back(&(*p));
		}
	}

	cvflann::Matrix<float> features(new float[points.size() * 2], points.size(), 2);
	for (auto i = 0u; i < points.size(); i++) {
		*(features.data + i * features.stride + 0) = points[i]->x();
		*(features.data + i * features.stride + 1) = points[i]->y();
	}
	points.clear();

	cvflann::KDTreeSingleIndex<cvflann::L2_Simple<float>> tree(features, cvflann::KDTreeSingleIndexParams(50, false, 2));
	tree.buildIndex();

	int2 center = grid.indexIntToInt2(cellIndex);
	int2 begin  = {center.x - 2, center.y - 2};
	int2 end    = {center.x + 2, center.y + 2};

	for(auto x = begin.x; x <= end.x; x++) {
		for(auto y = begin.y; y <= end.y; y++) {
			if(x == center.x && y == center.y) {
				continue;
			}
			else if(x == begin.x && (y == begin.y || y == end.y)) {
				continue;
			}
			else if(x == end.x && (y == begin.y || y == end.y)) {
				continue;
			}
			else{
				Cell* neighborCell = grid.cellAt(x, y);

				if(neighborCell != nullptr && neighborCell->isCore() && visitedCells->find(grid.indexInt2ToInt(x, y)) == visitedCells->end()) {
					if(cellsMustMerged(tree, *neighborCell, eps)) {
						mergeClustersDFS(grid, eps, grid.indexInt2ToInt(x, y), clusterIndex, visitedCells, clusterIndices);
					}
				}
			}
		}
	}

	delete[] features.data;
}




bool DBSCAN::cellsMustMerged(cvflann::KDTreeSingleIndex<cvflann::L2_Simple<float> > &kdTree, const Cell& neighborCell, float eps) const {
	bool find = false;

	cvflann::Matrix<float> query(new float[2], 1, 2);

	for(auto p2 = neighborCell.points()->begin(); p2 != neighborCell.points()->end(); p2++) {
		if (p2->isCore()) {
			*(query.data + 0) = p2->x();
			*(query.data + 1) = p2->y();

			cvflann::Matrix<float> dists;
			cvflann::Matrix<int> indices;

			kdTree.radiusSearch(query, indices, dists, eps, cvflann::SearchParams(32, eps, false));
			if (indices.rows > 0) {
				find = true;
			}
			delete[] indices.data;
			delete[] dists.data;
		}
	}

	delete[] query.data;

	return find;
}





void DBSCAN::determineBorderPoints(const DBSCANGrid& grid, int minPts, float eps, std::vector<int>* clusterIndices) const {
	for(auto entry = grid.cellsSparseMatrix().begin(); entry != grid.cellsSparseMatrix().end(); entry++) {
		if(grid.cellAt(entry->first)->points()->size() < minPts) {
			borderPointToNearestCluster(grid, eps, entry->first, clusterIndices);
		}
	}
}






void DBSCAN::borderPointToNearestCluster(const DBSCANGrid& grid, float eps, int index, std::vector<int>* clusterIndices) const {
	int2 center = grid.indexIntToInt2(index);
	int2 begin = {center.x - 2, center.y - 2};
	int2 end = {center.x + 2, center.y + 2};

	const Cell* cell = grid.cellAt(index);

	for(auto p1 = cell->points()->begin(); p1 != cell->points()->end(); p1++) {
		if(!p1->isCore()) {
			float dist;
			float minDist = eps;
			int minCluster = -1;

			for(auto x = begin.x; x <= end.x; x++) {
				for(auto y = begin.y; y <= end.y; y++) {
					if(x == begin.x && (y == begin.y || y == end.y)) {
						continue;
					}
					else if(x == end.x && (y == begin.y || y == end.y)) {
						continue;
					}
					else {
						int neighborIndex = grid.indexInt2ToInt(x, y);
						const Cell* neighborCell = grid.cellAt(neighborIndex);

						if (neighborCell != nullptr && neighborCell->isCore()) {
							for(auto p2 = neighborCell->points()->begin(); p2 != neighborCell->points()->end(); p2++) {
								if(p2->isCore()) {
									dist = euclideanDist2(*p1, *p2);
									if(dist <= minDist) {
										minDist = dist;
										minCluster = clusterIndices->at(p2->index());
									}
								}
							}
						}
					}
				}
			}

			clusterIndices->at(p1->index()) = minCluster;
		}
	}
}





float DBSCAN::euclideanDist2(const DBSCANPoint& point1, const DBSCANPoint& point2) const{
	float x;
	float y;

	x = point1.x() - point2.x();
	y = point1.y() - point2.y();

	return x * x + y * y;
}
