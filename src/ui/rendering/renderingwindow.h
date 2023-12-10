#ifndef RENDERINGWINDOW_H
#define RENDERINGWINDOW_H


#include <QLabel>
#include <QKeyEvent>
#include <QMainWindow>
#include "renderingwidget.h"


class RenderingWidget;

namespace Ui {
class RenderingWindow;
}



class RenderingWindow : public QMainWindow{
        Q_OBJECT


    public:
        explicit RenderingWindow(QWidget *parent = nullptr);

        virtual ~RenderingWindow() override;

		QLabel* labelInfo() const;

        RenderingWidget* renderingWidget() const;



    signals:
        void signalReset();

        void signalUpdate();

        void signalOpenDataset();

        void signalHighQuality(int);

        void signalSettings();

		void signalTFDesigner(bool);

        void signalScreenshot();


    protected:
        virtual void initComponents();

        virtual void keyPressEvent(QKeyEvent *event) override;

        virtual void wheelEvent(QWheelEvent* event) override;

        // virtual void keyReleaseEvent(QKeyEvent *event) override;




    private:
        RenderingWindow(const RenderingWindow &) = delete;

        RenderingWindow &operator =(const RenderingWindow &) = delete;

        QLabel *m_labelInfo;
        Ui::RenderingWindow *m_ui;



    private slots:
        void slotZoomIn();

        void slotZoomOut();

        void slotRotateXCounterclockwise();

        void slotRotateXClockwise();

        void slotRotateYCounterclockwise();

        void slotRotateYClockwise();

        void slotRotateZCounterclockwise();

        void slotRotateZClockwise();

        void slotEmitSignalOpenDataset();

        void slotEmitSignalSettings();

		void slotEmitSignalTFDesigner();

        void slotEmitSignalReset();

        void slotEmitSignalUpdate();

        void slotEmitSignalScreenshot();

        void slotEmitSignalHighQuality(int stateChanged);

        void slotDisplayAbout();
};



#endif // RENDERINGWINDOW_H
