#ifndef TFSETTINGSDIALOG_H
#define TFSETTINGSDIALOG_H


#include <QDialog>



namespace Ui {
class TFSettingsDialog;
}



class TFSettingsDialog : public QDialog{
        Q_OBJECT



    public:
        TFSettingsDialog(QWidget *parent = 0);

        virtual ~TFSettingsDialog();



    public slots:
		void slotSetFields(float size, float borderWidth, float zoomIncrement, float baseOpacity, float selectedOpacity, float unselectedOpacity, bool pivotLabelEnabled);


    signals:
		void signalAccepted(float size, float borderWidth, float zoomIncrement, float baseOpacity, float selectedOpacity, float unselectedOpacity, bool pivotLabelEnabled);

        void signalRejected();



    protected:
        virtual void initUI();



    private:
        TFSettingsDialog(const TFSettingsDialog &) = delete;
        TFSettingsDialog &operator =(const TFSettingsDialog &) = delete;

        Ui::TFSettingsDialog *m_ui;



    private slots:
        void slotEmitSignalAccepted();

        void slotEmitSignalRejected();
};



#endif // TFSETTINGSDIALOG_H
