#ifndef DBSCANPOINT_H
#define DBSCANPOINT_H


namespace clustering {


class DBSCANPoint {
public:
    DBSCANPoint();

    DBSCANPoint(float x, float y);

    DBSCANPoint(float x, float y, int index = 0);

    virtual ~DBSCANPoint();

    void setX(float x);

    float x() const;

    void setY(float y);

    float y() const;

    void setIndex(int index);

    int index() const;

    void setCore(bool isCore);

    bool isCore() const;



private:
    float m_x;
    float m_y;
    int m_index;
    bool m_core;
};


}



#endif // DBSCANPOINT_H
