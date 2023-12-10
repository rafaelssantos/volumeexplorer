#include "cluster.h"





using namespace std;
using namespace transfer_function;



Cluster::Cluster() {
    m_pivots = new vector<Pivot*>();
	m_index = -1;
}



Cluster::~Cluster() {
    for(unsigned i = 0; i < m_pivots->size(); i++){
        m_pivots->at(i) = nullptr;
    }
    delete m_pivots;
}






vector<Pivot*>* Cluster::pivots() const {
	return m_pivots;
}



int Cluster::index() const {
	return m_index;
}



void Cluster::setIndex(int index) {
	m_index = index;
}
