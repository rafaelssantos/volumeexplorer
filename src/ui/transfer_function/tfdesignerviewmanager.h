#ifndef TFDESIGNERVIEWMANAGER_H
#define TFDESIGNERVIEWMANAGER_H


#include <string>


class TFDesignerViewManager {
public:
	static TFDesignerViewManager& instance();

    float load(const std::string& filePath);

    void save(const std::string& filePath, const float zoomFactor);



private:
	TFDesignerViewManager();

	virtual ~TFDesignerViewManager();
};




#endif // TFDESIGNERVIEWMANAGER_H
