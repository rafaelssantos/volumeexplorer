#include "sparsespatialselection.h"

#include "log_utils/logger.h"
#include <cmath>


using namespace log_utils;
using namespace similarity_search;
using namespace std;




SparseSpatialSelection::SparseSpatialSelection() {

}



SparseSpatialSelection::~SparseSpatialSelection() {

}



set<int> *SparseSpatialSelection::exec(const vector<vector<float> >& instances, const set<int> &indices, float distFactor) const {
	float maxDist;
	set<int> *pivots = nullptr;


    maxDist = calcMaxDistance(instances, indices) * distFactor;
	pivots = new set<int>();
	pivots->insert(*(indices.begin()));


	bool chosen;
	if(maxDist != 0.0) {
		for(auto i = indices.begin(); i != indices.end(); i++) {
			chosen = true;
			for(auto j = pivots->begin(); j != pivots->end(); j++) {
				if(euclideanDist(instances, *i, *j) < maxDist) {
					chosen = false;
					break;
				}
			}
			if(chosen) {
				pivots->insert(*i);
			}
		}
	}

	return pivots;
}



float SparseSpatialSelection::calcMaxDistance(const vector<vector<float> >& instances, const std::set<int> &indices) const {
	unsigned indexA;
	unsigned indexB;
	float dist;
	float maxDist;

	indexB = indexA = *(indices.begin());

	maxDist = 0;

	for(auto i = indices.begin(); i != indices.end(); i++){
		dist = euclideanDist(instances, indexA, *i);
		if(dist > maxDist){
			maxDist = dist;
			indexB = *i;
		}
	}

	for(auto i = indices.begin(); i != indices.end(); i++){
		dist = euclideanDist(instances, indexB, *i);
		if(dist > maxDist){
			maxDist = dist;
			indexA = *i;
		}
	}

	return maxDist;
}




float SparseSpatialSelection::euclideanDist(const vector<vector<float> >& instances, int indexA, int indexB) const{
	float distance = 0;

	for(auto i = 0; i < instances.size(); i++){
		distance += pow(instances.at(i).at(indexA) -  instances.at(i).at(indexB), 2.0);
	}

	return sqrt(distance);
}
