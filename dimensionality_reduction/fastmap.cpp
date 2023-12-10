#include "fastmap.h"

#include <cmath>
#include "log_utils/logger.h"


using namespace std;
using namespace log_utils;
using namespace dimensionality_reduction;


FastMap::FastMap() {

}



FastMap::~FastMap() {

}





std::vector<std::vector<float> >* FastMap::exec(const volume::Volume &volume, const std::vector<std::vector<float>>& instances, unsigned k){
	int pivotA;
	int pivotB;
	float distAB, distAI, distBI;


	vector<vector<float>> *output = nullptr;

	output = new vector<vector<float>>(k);

	for(auto i = 0u; i < k; i++){
        output->at(i).resize(instances.front().size(), 0);
	}

    if(k > instances.size()){
        for(auto i = 0u; i < instances.front().size(); i++){
            for(auto d = 0u; d < instances.size(); d++){
                output->at(d).at(i) = instances.at(d).at(i);
			}
            for(size_t d = instances.size(); d < k; d++){
				output->at(d).at(i) = 0;
			}
		}
	}
	else{
		for(auto dims = 0u; dims < k; dims++){
            pickPivots(instances, *output, dims, &pivotA, &pivotB);

            distAB = calcDistance(instances, *output, dims, pivotA, pivotB);

			if(distAB == 0.0){
				break;
			}

            for(auto i = 0u; i < instances.front().size(); i++){
                distAI = calcDistance(instances, *output, dims, static_cast<int>(i), pivotA);
                distBI = calcDistance(instances, *output, dims, static_cast<int>(i), pivotB);
				output->at(dims).at(i) =  (distAI * distAI + distAB * distAB  - distBI * distBI) / (2.0 * distAB);
			}
		}
	}


	return output;
}





void FastMap::pickPivots(const std::vector<std::vector<float> >& instances,  const std::vector<std::vector<float> >& output, unsigned dims, int* pivotA, int* pivotB){
	*pivotB = furthest(instances, output, dims, 0);
	*pivotA = furthest(instances, output, dims, *pivotB);
}






int FastMap::furthest(const std::vector<std::vector<float> >& instances,  const std::vector<std::vector<float> >& output, unsigned dims, int index){
	float maxDist = 0;
	int maxDistIndex = index;
	float dist;


	for(auto i = 0u; i < instances.front().size(); i++){
		dist = calcDistance(instances, output, dims, index, static_cast<int>(i));
		if(dist > maxDist){
			maxDist = dist;
			maxDistIndex = static_cast<int>(i);
		}
	}

	return maxDistIndex;
}





float FastMap::calcDistance(const std::vector<std::vector<float> >& instances,  const std::vector<std::vector<float> >& output, unsigned dims, int indexA, int indexB){
	float distOriginal = euclideanDist(instances, indexA, indexB, static_cast<unsigned>(instances.size()));
	float distProjected = euclideanDist(output, indexA, indexB, dims);


	return sqrt(distOriginal * distOriginal - distProjected * distProjected);
}




float FastMap::euclideanDist(const std::vector<std::vector<float> >& instances, int indexA, int indexB, unsigned dims){
	float distance = 0;

	for(auto i = 0u; i < dims; i++){
		distance += pow(instances.at(i).at(static_cast<unsigned>(indexA)) -  instances.at(i).at(static_cast<unsigned>(indexB)), 2.0);
	}

	return sqrt(distance);
}
