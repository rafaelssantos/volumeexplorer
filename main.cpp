#include <locale>
#include <QApplication>

#include "ui/rendering/renderinguicontroller.h"
#include "ui/transfer_function/tfdesigneruicontroller.h"


int main(int argc, char *argv[]) {	
	QApplication app(argc, argv);

    setlocale(LC_ALL, "en_US.utf8");
    QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));

    RenderingUIController::instance().connecToFeatureUiController();
    TFDesignerUIController::instance().connecToRenderingUIController();

    RenderingUIController::instance().slotSetWindowVisible(true);

	return app.exec();
}
