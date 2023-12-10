#ifndef OBSERVERFILEDIALOG_H
#define OBSERVERFILEDIALOG_H


#include <string>
#include <QFileDialog>



class ObserverFileDialog : public QFileDialog {
    Q_OBJECT


public:
    ObserverFileDialog(QWidget *parent = nullptr);

    virtual ~ObserverFileDialog();


private:
    void initComponents();



signals:
    void signalAccepted(const std::string &file_path);

    void signalRejected();



private slots:
    void slotEmitSignalAccepted();

    void slotEmitSignalRejected();
};

#endif // OBSERVERFILEDIALOG_H
