#include "tfdesignfiledialog.h"

#include <QStringList>


using namespace std;





TFDesignFileDialog::TFDesignFileDialog(QWidget *parent) : QFileDialog (parent) {
    initComponents();
}





TFDesignFileDialog::~TFDesignFileDialog() {

}




void TFDesignFileDialog::initComponents() {
    QStringList filter;

    filter << "Transfer function design format (*.tfd)";

    setWindowTitle("Transfer Function Design Dialog");
    setNameFilters(filter);

    connect(this, SIGNAL(accepted()), this, SLOT(slotEmitSignalAccepted()));
    connect(this, SIGNAL(rejected()), this, SLOT(slotEmitSignalRejected()));
}




void TFDesignFileDialog::slotEmitSignalAccepted() {
    QString filePath = selectedFiles().first();

    QFileInfo fileInfo(filePath);
    if(fileInfo.suffix().isEmpty()) {
        int lastDot = selectedNameFilter().lastIndexOf('.');
        int lastParenthesis = selectedNameFilter().lastIndexOf(')');
        filePath += selectedNameFilter().mid(lastDot, lastParenthesis - lastDot);
    }
    emit signalAccepted(filePath.toStdString());
}





void TFDesignFileDialog::slotEmitSignalRejected() {
    emit signalRejected();
}
