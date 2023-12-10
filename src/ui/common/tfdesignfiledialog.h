#ifndef TFDESIGNFILEDIALOG_H
#define TFDESIGNFILEDIALOG_H


#include <string>
#include <QFileDialog>



class TFDesignFileDialog : public QFileDialog {
    Q_OBJECT


public:
    TFDesignFileDialog(QWidget *parent = nullptr);

    virtual ~TFDesignFileDialog();


private:
    void initComponents();



signals:
    void signalAccepted(const std::string &file_path);

    void signalRejected();



private slots:
    void slotEmitSignalAccepted();

    void slotEmitSignalRejected();
};

#endif // TFDESIGNFILEDIALOG_H
