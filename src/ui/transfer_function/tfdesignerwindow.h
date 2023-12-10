#ifndef TFDESIGNERWINDOW_H
#define TFDESIGNERWINDOW_H


#include <QKeyEvent>
#include <QLabel>
#include <QMainWindow>
#include <QProgressBar>
#include "tfdesignerspace.h"
#include "transfer_function/selectionmode.h"




namespace Ui {
class TFDesignerWindow;
}



class TFDesignerWindow : public QMainWindow{
		Q_OBJECT



	public:
		explicit TFDesignerWindow(QWidget *parent = nullptr);

		virtual ~TFDesignerWindow() override;

		TFDesignerSpace* view() const;

		QLabel *labelSatus() const;

		QProgressBar* progressBar() const;



	signals:
		void signalLeft();

		void signalRight();

        void signalZoom(graphics_utils::Zoom zoom);

        void signalSelectionModeChanged(transfer_function::SelectionMode selectionMode);

		void signalClustering();

		void signalSettingsDialog();

		void signalFeaturesExtraction();

		void signalUnselectAll();

		void signalUpdate();

		void signalRestorePos();

		void signalRestoreColor();

		void signalShowRenderingWindow();

		void signalColorChoose();

		void signalBenchmarkEnabled(bool enabled);

		void signalGroup();

		void signalUngroup();

		void signalScreenshot();

		void signalScreenshotForPivots();

		void signalScreenshotForClusters();

		void signalScreenshotForGroups();

		void signalSaveViewerPos();

		void signalLoadViewerPos();

		void signalSaveTFDesign();

		void signalLoadTFDesign();

		void signalShowLogWindow();


	protected:
		virtual void initComponents();

		virtual void keyPressEvent(QKeyEvent *event) override;



	private:
		TFDesignerWindow(const TFDesignerWindow &) = delete;
		TFDesignerWindow &operator =(const TFDesignerWindow &) = delete;

		Ui::TFDesignerWindow *m_ui;

		QLabel *m_lblStatus;



	private slots:
		void slotEmitSignalFeaturesExtraction();

		void slotEmitSignalClustering();

		void slotEmitSignalSettingsDialog();

		void slotEmitSignalUnselectAll();

		void slotEmitSignalResetObserver();

		void slotEmitSignalResetColor();

		void slotEmitSignalUpdate();

		void slotEmitSignalZoomIn();

		void slotEmitSignalZoomOut();

		void slotEmitSignalRight();

		void slotEmitSignalLeft();

		void slotEmitSignalShowRenderingWindow();

		void slotEmitSignalColorChoose();

		void slotEmitSignalPointSelection();

		void slotEmitSignalClusterSelection();

		void slotEmitSignalGroupSelection();

		void slotEmitSignalGroup();

		void slotEmitSignalUngroup();

		void slotEmitSignalScreenshot();

		void slotEmitSignalScreenshotForPivots();

		void slotEmitSignalScreenshotForClusters();

		void slotEmitSignalScreenshotForGroups();

		void slotEmitSignalShowLogWindow();

protected:
		void wheelEvent(QWheelEvent* event) override;
};



#endif // TFDESIGNERWINDOW_H
