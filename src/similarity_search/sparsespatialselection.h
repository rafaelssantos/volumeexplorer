#ifndef SPARSESPATIALSELECTION_H
#define SPARSESPATIALSELECTION_H



#include <vector>
#include <set>

namespace similarity_search {


class SparseSpatialSelection {
public:
    SparseSpatialSelection();

    virtual ~SparseSpatialSelection();

	std::set<int>* exec(const std::vector<std::vector<float>> &instances, const std::set<int>& indices, float distFactor) const;

    float euclideanDist(const std::vector<std::vector<float>>& instances, int indexA, int indexB) const;


private:
	float calcMaxDistance(const std::vector<std::vector<float>> &instances, const std::set<int>& indices) const;
};


}



#endif // SPARSESPATIALSELECTION_H
