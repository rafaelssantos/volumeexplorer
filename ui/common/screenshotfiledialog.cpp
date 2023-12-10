#include "screenshotfiledialog.h"




ScreenshotFileDialog::ScreenshotFileDialog(QWidget *parent) : QFileDialog(parent) {
    initComponents();
}





ScreenshotFileDialog::~ScreenshotFileDialog() {

}





void ScreenshotFileDialog::initComponents() {
    QStringList filter;

    filter << "Portable Network Graphics (*.png)"
           << "JPEG files (*.jpeg *.jpg)"
           << "Portable image format (*.ppm)"
           << "Windows bitmaps (*.bmp)"
           << "X11 Bitmap (*.xbm)"
           << "X11 Pixmap (*.xpm)";

    setWindowTitle("Save screenshot");
    setNameFilters(filter);
    setAcceptMode(QFileDialog::AcceptSave);
    setFileMode(QFileDialog::ExistingFile);

    connect(this, SIGNAL(accepted()), this, SLOT(slotEmitSignalAccepted()));
    connect(this, SIGNAL(rejected()), this, SLOT(slotEmitSignalRejected()));
}




void ScreenshotFileDialog::slotEmitSignalAccepted() {
    QString filePath = selectedFiles().first();

    QFileInfo fileInfo(filePath);
    if(fileInfo.suffix().isEmpty()) {
        int lastDot = selectedNameFilter().lastIndexOf('.');
        int lastParenthesis = selectedNameFilter().lastIndexOf(')');
        filePath += selectedNameFilter().mid(lastDot, lastParenthesis - lastDot);
    }
    emit signalAccepted(filePath);
}




void ScreenshotFileDialog::slotEmitSignalRejected() {
    emit signalRejected();
}
