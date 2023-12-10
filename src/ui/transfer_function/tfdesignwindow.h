#ifndef TFDESIGNWINDOW_H
#define TFDESIGNWINDOW_H


#include <QLabel>
#include <QProgressBar>
#include <QKeyEvent>
#include <QMainWindow>
#include "vex.h"
#include "tfdesignspace.h"




namespace Ui {
class TFDesignWindow;
}



class TFDesignWindow : public QMainWindow{
		Q_OBJECT



	public:
        explicit TFDesignWindow(QWidget *parent = nullptr);

        virtual ~TFDesignWindow() override;

		TFDesignSpace *view() const;

		QLabel *labelClusterCount() const;

		QProgressBar* progressBar() const;



	signals:
		void signalLeft();

		void signalRight();

        void signalZoom(graphics_utils::Zoom zoom);

        void signalSelectionModeChanged(transfer_function::SelectionMode selectionMode);

		void signalClustering();

		void signalSettingsDialog();

        void signalAttributeExtraction();

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

		void signalScreenshotForCluster();

		void signalScreenshotForGroup();

		void signalSaveViewerPos();

		void signalLoadViewerPos();

		void signalSaveTFDesign();

		void signalLoadTFDesign();

		void signalShowLogWindow();


	protected:
		virtual void initComponents();

		virtual void keyPressEvent(QKeyEvent *event) override;



	private:
        TFDesignWindow(const TFDesignWindow &) = delete;
        TFDesignWindow &operator =(const TFDesignWindow &) = delete;

        Ui::TFDesignWindow *m_ui;

		QLabel *m_lblClusterCount;



	private slots:
        void slotEmitSignalAttributeExtraction();

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

		void slotEmitBenchmarkEnabled();

		void slotEmitSignalPointSelection();

		void slotEmitSignalClusterSelection();

		void slotEmitSignalGroupSelection();

		void slotEmitSignalGroup();

		void slotEmitSignalUngroup();

		void slotEmitSignalScreenshot();

		void slotEmitSignalScreenshotForCluster();

		void slotEmitSignalScreenshotForGroup();

		void slotEmitSignalSaveViewerPos();

		void slotEmitSignalLoadViewerPos();

		void slotEmitSignalSaveTFDesign();

		void slotEmitSignalLoadTFDesign();

		void slotEmitSignalShowLogWindow();

protected:
		void wheelEvent(QWheelEvent* event) override;
};



#endif // TFDESIGNWINDOW_H
