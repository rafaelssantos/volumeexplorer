#ifndef TFDESIGNSPACE_H
#define TFDESIGNSPACE_H


#include <QGraphicsView>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QWheelEvent>
#include "graphics_utils/zoom.h"



class TFDesignSpace : public QGraphicsView{
    Q_OBJECT



public:
    explicit TFDesignSpace(QWidget *parent);

    virtual ~TFDesignSpace() override;



protected:
    void initComponents();

    void mouseDoubleClickEvent(QMouseEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;




private:
    TFDesignSpace(const TFDesignSpace &) = delete;
    TFDesignSpace &operator =(const TFDesignSpace &) = delete;


signals:
    void signalSizeChanged(int width, int height);


private slots:
    void slotEmitSignalSizeChanged();
};


#endif // TFDESIGNSPACE_H
