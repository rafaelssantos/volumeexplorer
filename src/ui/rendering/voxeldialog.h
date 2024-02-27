#ifndef VOXELDIALOG_H
#define VOXELDIALOG_H

#include <QDialog>
#include <string>


namespace Ui {
class VoxelDialog;
}



class VoxelDialog : public QDialog {
	Q_OBJECT



public:
	VoxelDialog(QWidget *parent = nullptr);

	virtual ~VoxelDialog();



	std::string dirPath() const;

	void setDirPath(const std::string& dirPath);

signals:
    void signalAccepted(float x, float y, float z);

	void signalRejected();



protected:
	virtual void initComponents();



private:
	Ui::VoxelDialog *m_ui;

	std::string m_dirPath;


private slots:
	void slotEmitSignalAccepted();

	void slotEmitSignalRejected();
};



#endif // VOXELDIALOG_H
