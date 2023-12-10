#include "tfdesignspace.h"


#include <QPainterPath>
#include <QRubberBand>

using namespace graphics_utils;



TFDesignSpace::TFDesignSpace(QWidget* parent) : QGraphicsView(parent){
	initComponents();
}






TFDesignSpace::~TFDesignSpace(){

}






void TFDesignSpace::initComponents(){
	setScene(new QGraphicsScene(this));
	setInteractive(true);
	setRenderHint(QPainter::Antialiasing, true);
	setDragMode(QGraphicsView::RubberBandDrag);
	setRubberBandSelectionMode(Qt::ContainsItemShape);
}






void TFDesignSpace::mouseDoubleClickEvent(QMouseEvent *event){
	event->setModifiers(Qt::ControlModifier);
	QGraphicsView::mouseDoubleClickEvent(event);
}





void TFDesignSpace::mousePressEvent(QMouseEvent *event){
	event->setModifiers(Qt::ControlModifier);
	QGraphicsView::mousePressEvent(event);
}






void TFDesignSpace::mouseReleaseEvent(QMouseEvent *event){
	event->setModifiers(Qt::ControlModifier);
	QGraphicsView::mouseReleaseEvent(event);


}





void TFDesignSpace::resizeEvent(QResizeEvent *event){
	slotEmitSignalSizeChanged();

	QGraphicsView::resizeEvent(event);
}






void TFDesignSpace::slotEmitSignalSizeChanged(){
	emit signalSizeChanged(width(), height());
}






