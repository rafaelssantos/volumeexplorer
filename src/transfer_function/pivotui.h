#ifndef PIVOTUI_H
#define PIVOTUI_H


#include <QGraphicsEllipseItem>
#include <QObject>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <cuda_runtime.h>



namespace transfer_function {

class PivotUI :public QObject, public QGraphicsEllipseItem{
    Q_OBJECT


public:
	PivotUI(int index, float2 basePos);

    void setIndex(int index);

    int index() const;

	virtual ~PivotUI() override;

    void setBorderWidth(float width);

    float borderWidth() const;

    void setColor(float red, float green, float blue, float opacity);

    void setColor(const float4& color);

    void setUnselectedOpacity(float opacity);

    const float4& color() const;

    void setBasePos(const float2& basePos);

    const float2& basePos() const;

    void setSelected(bool selected, bool silenced);

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;



protected:
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &index) override;



private:
    void initComponents();

    float4 m_color;
    QBrush m_brush;
    QPen m_pen;
    int m_index;
    float2 m_basePos;
    bool m_selectionSilenced;


signals:
    void signalSelect(bool selected, int index);
};


}

#endif // PIVOTUI_H
