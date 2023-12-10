#ifndef TFDESIGNERSPACE_H
#define TFDESIGNERSPACE_H


#include <QGraphicsView>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QWheelEvent>
#include "graphics_utils/zoom.h"



class TFDesignerSpace : public QGraphicsView{
    Q_OBJECT



public:
	explicit TFDesignerSpace(QWidget *parent);

	virtual ~TFDesignerSpace() override;



protected:
    void initComponents();

    void mouseDoubleClickEvent(QMouseEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;




private:
	TFDesignerSpace(const TFDesignerSpace &) = delete;
	TFDesignerSpace &operator =(const TFDesignerSpace &) = delete;


signals:
    void signalSizeChanged(int width, int height);


private slots:
    void slotEmitSignalSizeChanged();
};


#endif // TFDESIGNERSPACE_H
