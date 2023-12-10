#include "observerfiledialog.h"

#include <QStringList>


using namespace std;





ObserverFileDialog::ObserverFileDialog(QWidget *parent) : QFileDialog (parent) {
    initComponents();
}





ObserverFileDialog::~ObserverFileDialog() {

}




void ObserverFileDialog::initComponents() {
    QStringList filter;

    filter << "Observer Format (*.of)";

    setWindowTitle("Observer Dialog");
    setNameFilters(filter);

    connect(this, SIGNAL(accepted()), this, SLOT(slotEmitSignalAccepted()));
    connect(this, SIGNAL(rejected()), this, SLOT(slotEmitSignalRejected()));
}




void ObserverFileDialog::slotEmitSignalAccepted() {
    QString filePath = selectedFiles().first();

    QFileInfo fileInfo(filePath);
    if(fileInfo.suffix().isEmpty()) {
        int lastDot = selectedNameFilter().lastIndexOf('.');
        int lastParenthesis = selectedNameFilter().lastIndexOf(')');
        filePath += selectedNameFilter().mid(lastDot, lastParenthesis - lastDot);
    }
    emit signalAccepted(filePath.toStdString());
}





void ObserverFileDialog::slotEmitSignalRejected() {
    emit signalRejected();
}
