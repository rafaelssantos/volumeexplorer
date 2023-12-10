#ifndef CLUSTERINGUICONTROLLER_H
#define CLUSTERINGUICONTROLLER_H


#include <QObject>



class ClusteringUIController : public QObject {
    Q_OBJECT


public slots:
    int slotExecDialog();


signals:
    void signalClustered();



public:
	static ClusteringUIController& instance();


private:
	ClusteringUIController();

	virtual ~ClusteringUIController();

    unsigned m_minPoints;
	float m_eps;
    float m_alpha;


private slots:
	void sloDialogAccepted(int minPoints, float eps, float distFactor);

    void slotDialogRejected();


private:
	ClusteringUIController(const ClusteringUIController &) = delete;
	ClusteringUIController &operator =(const ClusteringUIController &) = delete;

};



#endif // CLUSTERINGUICONTROLLER_H
