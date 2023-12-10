#ifndef DIRECTORYFILEDIALOG_H
#define DIRECTORYFILEDIALOG_H


#include <QFileDialog>



class DirectotyFileDialog : public QFileDialog {
    Q_OBJECT

public:
    DirectotyFileDialog(QWidget *parent = nullptr);

    virtual ~DirectotyFileDialog();



private:
    void initComponents();



signals:
    void signalAccepted(QString path);

    void signalRejected();



private slots:
    void slotEmitSignalAccepted();

    void slotEmitSignalRejected();
};


#endif // DIRECTORYFILEDIALOG_H
