#ifndef DBSCANGRID_H
#define DBSCANGRID_H

#include <map>
#include <vector>
#include <cuda_runtime.h>
#include "dbscancell.h"
#include "dbscanpoint.h"
#include "volume/volume.cuh"




namespace clustering {

class DBSCANGrid {
public:
    DBSCANGrid(const volume::Volume& volume, const std::vector<std::vector<float>> &instances, float eps);

    virtual ~DBSCANGrid();

    int2 posToInt2Index(float x, float y) const;

    int posToIntIndex(float x, float y) const;

    size_t pointCount() const;

    int cols() const;

    int rows() const;

    virtual void release();

    Cell *cellAt(int x, int y) const;

    Cell* cellAt(int index) const;

    int2 indexIntToInt2(int index) const;

    int indexInt2ToInt(int x, int y) const;

    const std::map<int, Cell *>& cellsSparseMatrix() const;



private:
    void calcBounds(const volume::Volume& volume, const std::vector<std::vector<float> >& instances);


private:
    float m_cellSide;
    float m_eps;
    float2 m_minBound;
    float2 m_maxBound;
    size_t m_pointCount;
    int m_rows;
    int m_cols;
    std::map<int, Cell *> m_cellsSparseMatrix;



private:
    DBSCANGrid(const DBSCANGrid &) = delete;
    DBSCANGrid &operator=(const DBSCANGrid &) = delete;
};


}

#endif // DBSCANGRID_H
