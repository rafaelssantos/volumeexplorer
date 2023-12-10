#include "dbscanpoint.h"


using namespace clustering;




DBSCANPoint::DBSCANPoint() {
    m_core = false;
    m_x = 0;
    m_y = 0;
    m_index = 0;
}



DBSCANPoint::DBSCANPoint(float x, float y) {
    m_core = false;
    m_x = x;
    m_y = y;
    m_index = 0;
}





DBSCANPoint::DBSCANPoint(float x, float y, int index) {
    m_core = false;
    m_x = x;
    m_y = y;
    m_index = index;
}




DBSCANPoint::~DBSCANPoint() {

}





void DBSCANPoint::setX(float x) {
    m_x = x;
}





float DBSCANPoint::x() const {
    return  m_x;
}





void DBSCANPoint::setY(float y) {
    m_y = y;
}





float DBSCANPoint::y() const {
    return m_y;
}




void DBSCANPoint::setIndex(int index) {
    m_index = index;
}





int DBSCANPoint::index() const {
    return m_index;
}




void DBSCANPoint::setCore(bool core) {
    m_core = core;
}




bool DBSCANPoint::isCore() const {
    return m_core;
}
