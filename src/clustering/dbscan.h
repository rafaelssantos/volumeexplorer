#ifndef GRIDDBSCAN_H
#define GRIDDBSCAN_H


#include <opencv2/flann.hpp>
#include <set>
#include <vector>
#include "dbscangrid.h"
#include "dbscanpoint.h"
#include "volume/volume.cuh"


namespace clustering {

class DBSCAN {
public:
    DBSCAN();

    virtual ~DBSCAN();

    std::vector<int>* exec(const volume::Volume& volume, const std::vector<std::vector<float>> &data, float eps, int minPts);


protected:
	void determineCorePoints(const DBSCANGrid &grid, int minPts, float eps) const;

    bool hasMoreThanMinPts(const DBSCANGrid &grid, const Cell &cell, const DBSCANPoint& point, int minPts, float eps) const;

	void mergeClusters(const DBSCANGrid &grid, float eps, std::vector<int> *clusterIndices) const;

    void mergeClustersDFS(const DBSCANGrid &grid, float eps,  int cellIndex, int clusterIndex, std::set<int> *visitedCells, std::vector<int> *clusterIndices) const;

    bool cellsMustMerged(cvflann::KDTreeSingleIndex<cvflann::L2_Simple<float>>& tree, const Cell& neighborCell, float eps) const;

	void determineBorderPoints(const DBSCANGrid &grid, int minPts, float eps, std::vector<int> *clusterIndices) const;

    void borderPointToNearestCluster(const DBSCANGrid &grid, float eps, int index, std::vector<int> *clusterIndices) const;

    float euclideanDist2(const DBSCANPoint &point1, const  DBSCANPoint& point2) const;
};
}




#endif // GRIDDBSCAN_H
