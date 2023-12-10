#include "directoryfiledialog.h"




DirectotyFileDialog::DirectotyFileDialog(QWidget *parent) : QFileDialog(parent) {
    initComponents();
}





DirectotyFileDialog::~DirectotyFileDialog() {

}





void DirectotyFileDialog::initComponents() {
    setWindowTitle("Save screenshots");
    setAcceptMode(QFileDialog::AcceptSave);
    setFileMode(QFileDialog::Directory);

    connect(this, SIGNAL(accepted()), this, SLOT(slotEmitSignalAccepted()));
    connect(this, SIGNAL(rejected()), this, SLOT(slotEmitSignalRejected()));
}




void DirectotyFileDialog::slotEmitSignalAccepted() {
    QString path = selectedFiles().first();

    emit signalAccepted(path);
}




void DirectotyFileDialog::slotEmitSignalRejected() {
    emit signalRejected();
}
