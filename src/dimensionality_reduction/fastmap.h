#ifndef FASTMAP_H
#define FASTMAP_H


#include <vector>
#include "volume/volume.cuh"



namespace dimensionality_reduction {
	class FastMap {
		public:
			FastMap();

			virtual ~FastMap();

			std::vector<std::vector<float>>* exec(const volume::Volume& volume, const std::vector<std::vector<float>>& instances, unsigned k);

			float euclideanDist(const std::vector<std::vector<float>>& instances, int indexA, int indexB, unsigned dims);


		protected:
			int furthest(const std::vector<std::vector<float>>& instances, const std::vector<std::vector<float>>& output, unsigned dims, int index);

			float calcDistance(const std::vector<std::vector<float>>& instances, const std::vector<std::vector<float>>& output, unsigned dims, int indexA, int indexB);

			void pickPivots(const std::vector<std::vector<float>>& instances, const std::vector<std::vector<float>>& output, unsigned dims, int* pivotA, int* pivotB);
	};
}



#endif // FASTMAP_H
