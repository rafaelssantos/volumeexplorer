#ifndef TFDESIGNUICONTROLLER_H
#define TFDESIGNUICONTROLLER_H


#include <vector>
#include <QObject>
#include <QGraphicsPolygonItem>
#include <cuda_runtime.h>
#include "tfdesignwindow.h"
#include "vex.h"




class TFDesignUIController: public QObject {
	Q_OBJECT



public:
    static TFDesignUIController& instance();

    void updatePivots();

	void setProgressBarVisible(bool visible);

	void setProgressBarValue(int value);

	void connecToRenderingUiController();

	void drawSelectRegion();


private:
    TFDesignUIController();

    virtual ~TFDesignUIController();

	void init();


private:
	float m_zoomFactor;
	TFDesignWindow m_window;
    transfer_function::SelectionMode m_selectionMode;
	bool m_isScreenshotOfClusters;
    int m_curPivot;
	int m_curGroup;
	int m_curCluster;
	QGraphicsPolygonItem m_selectionRegion;

private:
	//Desabilitados
    TFDesignUIController(const TFDesignUIController&) = delete;
    void operator=(const TFDesignUIController&) = delete;



public slots:
	void slotSetWindowVisible(bool visible = true);

	void slotUpdate();

	void slotUnselectAll();

	void slotErasePlot();

	void slotPlot();

	void slotExportScreenshot(QString  path);

	void slotExportScreenshots(QString path);


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

	void slotExecScreenshotDialogForCluster();

	void slotExecScreenshotDialogForGroup();

	void slotNext();

	void slotPrevious();

	void slotLoadTFDesignAccepted(std::string path);

	void slotLoadTFDesign();

	void slotSaveTFDesignAccepted(std::string path);

	void slotSaveTFDesign();

	void slotLoadObserverAccepted(std::string path);

	void slotLoadObserver();

	void slotSaveObserverAccepted(std::string path);

	void slotSaveObserverPos();

	void slotBenchmarkEnabled(bool enabled);

	void slotSetBenchmarkWindowVisible(bool visible = true);
};

#endif // TFDESIGNUICONTROLLER_H
