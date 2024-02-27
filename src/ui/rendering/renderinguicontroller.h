#ifndef RENDERINGUICONTROLLER_H
#define RENDERINGUICONTROLLER_H

#include <string>
#include <vector>
#include <QObject>
#include "graphics_utils/rotatationsense.h"
#include "graphics_utils/rotationaxis.h"
#include "graphics_utils/zoom.h"
#include "renderingwindow.h"






class RenderingUIController : public QObject {
	Q_OBJECT


public:
	static RenderingUIController& instance();

	void connecToFeatureUiController();

private:
	RenderingUIController();

	virtual ~RenderingUIController();

	void init();

	RenderingWindow m_window;
	std::list<std::string> m_datasetFilesPath;
	std::string m_dirPath;
	float m_volumeSpacingX;
	float m_volumeSpacingY;
    float m_volumeSpacingZ;



public slots:
    void slotRender(int width, int height);

    void slotRender();

	void slotRegisterGlPBOAsResource(GLuint pbo);

	void slotUnregisterGlPBOAsResource();

	void slotSetWindowVisible(bool visible = true);

    void slotZoom(graphics_utils::Zoom zoom);

    void slotRotate(graphics_utils::RotationAxis axis, graphics_utils::RotationSense sense);

    void slotUpdate();

	void slotResetViewer();

	void slotExecScreenshotDialog();

	void slotExportScreenshot(QString  path);




private slots:
	void slotSetDatasetFilesPath(std::list<std::string> filesPath, std::string dirPath);

    void slotSetVolumeSpacing(float x, float y, float z);

	void slotExecOpenDatasetDialog();

};

#endif // RENDERINGUICONTROLLER_H
