#include "tfdesignerviewmanager.h"


#include <fstream>


using namespace std;





TFDesignerViewManager& TFDesignerViewManager::instance() {
	static TFDesignerViewManager instance;

    return instance;
}





float TFDesignerViewManager::load(const string& filePath) {
    ifstream file;
    file.open(filePath);

    float zoomFactor = 0.0f;

    if(file.is_open()) {
        file >> zoomFactor;
    }

    file.close();

    return zoomFactor;
}





void TFDesignerViewManager::save(const string& filePath, const float zoomFactor) {
    ofstream file;
    file.open(filePath);

    if(file.is_open()) {
        file << zoomFactor << "\n";
    }

    file.close();
}





TFDesignerViewManager::TFDesignerViewManager() {

}





TFDesignerViewManager::~TFDesignerViewManager() {

}
