#ifndef DATASETFILEDIALOG_H
#define DATASETFILEDIALOG_H


#include <list>
#include <string>
#include <QFileDialog>



class DatasetFileDialog : public QFileDialog {
	Q_OBJECT



public:
	DatasetFileDialog();

	virtual ~DatasetFileDialog();



signals:
	void signalAccepted(const std::list<std::string> &files, std::string dirPath);

	void signalRejected();



protected:
	virtual void initComponents();



private slots:
	void slotEmitSignalAccepted();

	void slotEmitSignalRejected();
};



#endif // DATASETFILEDIALOG_H
