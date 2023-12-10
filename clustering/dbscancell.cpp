#include "dbscancell.h"



using namespace std;
using namespace clustering;




Cell::Cell() {
    m_points = new vector<DBSCANPoint>();
    m_core = false;
}






Cell::~Cell() {
    delete m_points;
    m_points = nullptr;
}





std::vector<DBSCANPoint>* Cell::points() const {
    return m_points;
}





void Cell::setCore(bool core) {
    m_core = core;
}




bool Cell::isCore() const {
    return m_core;

}
