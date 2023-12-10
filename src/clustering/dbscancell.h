#ifndef CELL_H
#define CELL_H


#include <vector>
#include "dbscanpoint.h"




namespace clustering {


class Cell {
public:
    Cell();

    virtual ~Cell();

    std::vector<DBSCANPoint>* points() const;

    void setCore(bool isCore);

    bool isCore() const;



private:
    std::vector<DBSCANPoint>* m_points;
    bool m_core;
};


}



#endif // CELL_H
