#ifndef CLUSTER_H
#define CLUSTER_H


#include <vector>
#include "pivot.h"



namespace transfer_function {
	class Cluster {
		public:
			Cluster();

			virtual ~Cluster();

			std::vector<Pivot*>* pivots() const;

			int index() const;

			void setIndex(int index);

	private:
			std::vector<Pivot*>* m_pivots;
			int m_index;
	};
}



#endif // CLUSTER_H
