#include "dbscangrid.h"


#include <cmath>
using namespace std;
using namespace clustering;






DBSCANGrid::DBSCANGrid(const volume::Volume &volume, const vector<vector<float> >& instances, float eps) {
    m_eps = eps;
    m_pointCount = instances.front().size();

    calcBounds(volume, instances);


    for(auto i = 0u; i < m_pointCount; i++) {
        DBSCANPoint point(instances.front().at(i), instances.back().at(i), i);

        int index = posToIntIndex(point.x(), point.y());

        if(m_cellsSparseMatrix.count(index) == 0) {
            Cell *cell = new Cell();
            cell->points()->emplace_back(point);
            m_cellsSparseMatrix[index] = cell;
        }

        else{
            m_cellsSparseMatrix[index]->points()->emplace_back(point);
        }

    }
}




DBSCANGrid::~DBSCANGrid() {
    release();
}





int DBSCANGrid::posToIntIndex(float x, float y) const {
    int col = static_cast<int>((x - m_minBound.x) / m_cellSide);
    int row = static_cast<int>((y - m_minBound.y) / m_cellSide);
    return row * m_cols + col;
}






int2 DBSCANGrid::posToInt2Index(float x, float y) const {
    int2 index;

    index.x = static_cast<int>((x - m_minBound.x) / m_cellSide);
    index.y = static_cast<int>((y - m_minBound.y) / m_cellSide);


    return index;
}





int2 DBSCANGrid::indexIntToInt2(int index) const {
    int2 index2;

    index2.x = index % m_cols;
    index2.y = index / m_cols;

    return index2;
}




int DBSCANGrid::indexInt2ToInt(int x, int y) const {
    if(x < 0 || x >= m_cols || y < 0 || y >= m_rows) {
        return -1;
    }
    else{
        return y * m_cols + x;
    }
}





size_t DBSCANGrid::pointCount() const {
    return m_pointCount;
}




int DBSCANGrid::cols() const {
    return m_cols;
}





int DBSCANGrid::rows() const {
    return m_rows;
}





void DBSCANGrid::release() {
    for(auto entry = m_cellsSparseMatrix.begin(); entry != m_cellsSparseMatrix.end(); entry++) {
        delete entry->second;
        entry->second = nullptr;
    }

    m_cellsSparseMatrix.clear();
}





Cell* DBSCANGrid::cellAt(int x, int y) const {
    if(x < 0 || y < 0 || x >= m_cols || y >= m_rows){
        return nullptr;
    }

    int index = indexInt2ToInt(x, y);

    if(m_cellsSparseMatrix.count(index) == 0) {
        return nullptr;
    }
    else{
        return m_cellsSparseMatrix.at(index);
    }
}




Cell* DBSCANGrid::cellAt(int index) const {
    int2 index2 = indexIntToInt2(index);

    if(index2.x < 0 || index2.y < 0 || index2.x >= m_cols || index2.y >= m_rows){
        return nullptr;
    }

    if(m_cellsSparseMatrix.count(index) == 0) {
        return nullptr;
    }
    else{
        return m_cellsSparseMatrix.at(index);
    }
}





const std::map<int, Cell*> &DBSCANGrid::cellsSparseMatrix() const {
    return m_cellsSparseMatrix;
}





void DBSCANGrid::calcBounds(const volume::Volume &volume, const std::vector<std::vector<float> >& instances) {
    m_minBound.x = instances.front().front();
    m_maxBound.x = instances.front().front();
    m_minBound.y = instances.back().front();
    m_maxBound.y = instances.back().front();

    for(auto i = 0; i < instances.front().size(); i++) {
        if(instances.front().at(i) < m_minBound.x) {
            m_minBound.x = instances.front().at(i);
        }
        if(instances.front().at(i) > m_maxBound.x) {
            m_maxBound.x = instances.front().at(i);
        }
        if(instances.back().at(i) < m_minBound.y) {
            m_minBound.y = instances.back().at(i);
        }
        if(instances.back().at(i) > m_maxBound.y) {
            m_maxBound.y = instances.back().at(i);
        }
    }

    m_cellSide = m_eps / sqrtf(2.0f);
    m_cols = static_cast<int>((m_maxBound.x - m_minBound.x) / m_cellSide) + 1;
    m_rows = static_cast<int>((m_maxBound.y - m_minBound.y) / m_cellSide) + 1;
}
