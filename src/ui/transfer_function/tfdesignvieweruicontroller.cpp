#include "tfdesignvieweruicontroller.h"


#include <fstream>


using namespace std;





TFDesignViewerUIController& TFDesignViewerUIController::instance() {
    static TFDesignViewerUIController instance;

    return instance;
}





float TFDesignViewerUIController::load(const string& filePath) {
    ifstream file;
    file.open(filePath);

    float zoomFactor = 0.0f;

    if(file.is_open()) {
        file >> zoomFactor;
    }

    file.close();

    return zoomFactor;
}





void TFDesignViewerUIController::save(const string& filePath, const float zoomFactor) {
    ofstream file;
    file.open(filePath);

    if(file.is_open()) {
        file << zoomFactor << "\n";
    }

    file.close();
}





TFDesignViewerUIController::TFDesignViewerUIController() {

}





TFDesignViewerUIController::~TFDesignViewerUIController() {

}
