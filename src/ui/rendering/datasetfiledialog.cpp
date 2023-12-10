#include "datasetfiledialog.h"


#include <QStringList>
#include <iostream>
#include <QDir>

using namespace std;





DatasetFileDialog::DatasetFileDialog() : QFileDialog() {
	initComponents();
}





DatasetFileDialog::~DatasetFileDialog() {

}






void DatasetFileDialog::initComponents() {


	setWindowTitle("Open Volume Dataset");
	setFileMode(QFileDialog::Directory);
    setAcceptMode(QFileDialog::AcceptOpen);


	connect(this, SIGNAL(accepted()), this, SLOT(slotEmitSignalAccepted()));
	connect(this, SIGNAL(rejected()), this, SLOT(slotEmitSignalRejected()));
}





void DatasetFileDialog::slotEmitSignalAccepted() {
	list<string> files;

	QStringList filters;
	filters << "*.bmp" << "*.dib" << "*.jpeg" << "*.jpg" << "*.jpe" << "*.jp2" << "*.png" << "*.webp" << "*.pbm" << "*.pgm" << "*.ppm" << "*.sr" << "*.ras" << "*.tiff" << "*.tif";


	QDir dir(selectedFiles().first());
	dir.setNameFilters(filters);

	QStringList qs_files_path = dir.entryList(QDir::Files);

	for (auto path = qs_files_path.begin(); path != qs_files_path.end(); path++) {
		files.emplace_back(dir.absolutePath().toStdString()+"/"+path->toStdString());
	}
	files.sort();

	emit signalAccepted(files, dir.absolutePath().toStdString());
}





void DatasetFileDialog::slotEmitSignalRejected() {
	emit signalRejected();
}
