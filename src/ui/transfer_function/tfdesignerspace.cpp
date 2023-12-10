#include "tfdesignerspace.h"


#include <QPainterPath>
#include <QRubberBand>


using namespace graphics_utils;



TFDesignerSpace::TFDesignerSpace(QWidget* parent) : QGraphicsView(parent){
	initComponents();
}






TFDesignerSpace::~TFDesignerSpace(){
}






void TFDesignerSpace::initComponents(){
	setScene(new QGraphicsScene(this));
	setInteractive(true);
	setRenderHint(QPainter::Antialiasing);
	setDragMode(QGraphicsView::RubberBandDrag);
	setRubberBandSelectionMode(Qt::ContainsItemShape);
}






void TFDesignerSpace::mouseDoubleClickEvent(QMouseEvent *event){
	event->setModifiers(Qt::ControlModifier);
	QGraphicsView::mouseDoubleClickEvent(event);
}





void TFDesignerSpace::mousePressEvent(QMouseEvent *event){
	event->setModifiers(Qt::ControlModifier);
	QGraphicsView::mousePressEvent(event);
}






void TFDesignerSpace::mouseReleaseEvent(QMouseEvent *event){
	event->setModifiers(Qt::ControlModifier);
	QGraphicsView::mouseReleaseEvent(event);


}





void TFDesignerSpace::resizeEvent(QResizeEvent *event){
	slotEmitSignalSizeChanged();

	QGraphicsView::resizeEvent(event);
}






void TFDesignerSpace::slotEmitSignalSizeChanged(){
	emit signalSizeChanged(width(), height());
}






