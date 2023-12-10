#ifndef SCREENSHOTFILEDIALOG_H
#define SCREENSHOTFILEDIALOG_H


#include <QFileDialog>



class ScreenshotFileDialog : public QFileDialog {
    Q_OBJECT

public:
    ScreenshotFileDialog(QWidget *parent = nullptr);

    virtual ~ScreenshotFileDialog();



private:
    void initComponents();



signals:
    void signalAccepted(QString file_path);

    void signalRejected();



private slots:
    void slotEmitSignalAccepted();

    void slotEmitSignalRejected();
};


#endif // SCREENSHOTFILEDIALOG_H
