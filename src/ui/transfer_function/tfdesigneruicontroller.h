#ifndef TFDESIGNERUICONTROLLER_H
#define TFDESIGNERUICONTROLLER_H


#include <vector>
#include <QObject>
#include <QGraphicsPolygonItem>
#include <cuda_runtime.h>
#include "tfdesignerwindow.h"




class TFDesignerUIController: public QObject {
	Q_OBJECT



public:
	static TFDesignerUIController& instance();

    void updatePivots();

	void setProgressBarVisible(bool visible);

	void setProgressBarValue(int value);

	void connecToRenderingUIController();



private:
	TFDesignerUIController();

	virtual ~TFDesignerUIController();

	void init();


private:
	float m_zoomFactor;
	TFDesignerWindow m_window;
    transfer_function::SelectionMode m_selectionMode;
    int m_curPivot;
	int m_curGroup;
	int m_curCluster;
	float m_maxDistPivot;
	float m_pivotMaxChildrenCount;
	float m_pivotMinChildrenCount;

    void pivotsLimitsCalc();


public slots:
	void slotSetWindowVisible(bool visible = true);

	void slotUpdate();

	void slotUnselectAll();

	void slotErasePlot();

	void slotPlot();

	void slotScreenshot(QString  path);

    void slotPivotScreenshot(QString path);

    void slotClusterScreenshot(QString path);

    void slotGroupScreenshot(QString path);



private slots:
	void slotResetColor();

	void slotResetObserver();

	void slotSelectColor();

	void slotColorSelected(const QColor &color);

	void slotResize(int width, int height);

    void slotZoom(graphics_utils::Zoom zoom);

	void slotSelect(bool selected, int index);

    void slotSelectionMode(transfer_function::SelectionMode selectionMode);

	void slotGroup();

	void slotUngroup();

	void slotExecScreenshotDialog();

	void slotExecScreenshotDialogForPivots();

	void slotExecScreenshotDialogForClusters();

	void slotExecScreenshotDialogForGroups();

	void slotNext();

	void slotPrevious();

	void slotSetLogWindowVisible(bool visible = true);
};

#endif // TFDESIGNERUICONTROLLER_H
