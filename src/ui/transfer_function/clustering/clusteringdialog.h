#ifndef CLUSTERINGDIALOG_H
#define CLUSTERINGDIALOG_H


#include <QDialog>



namespace Ui {
class ClusteringDialog;
}




class ClusteringDialog : public QDialog{
    Q_OBJECT



public:
    ClusteringDialog(QWidget *parent = nullptr);

    virtual ~ClusteringDialog() override;

	void setFields(int minPoints, float eps, float alpha);



protected:
    virtual void initComponents();



private:
    Ui::ClusteringDialog *m_ui;



signals:
	void signalAccepted(int minPoints, float eps, float alpha);

    void signalRejected();



private slots:
    void slotEmitSignalAccepted();

    void slotEmitSignalRejected();
};



#endif // CLUSTERINGDIALOG_H
