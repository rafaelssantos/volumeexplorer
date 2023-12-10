#ifndef TFDESIGNVIEWERUICONTROLLER_H
#define TFDESIGNVIEWERUICONTROLLER_H


#include <string>


class TFDesignViewerUIController {
public:
    static TFDesignViewerUIController& instance();

    float load(const std::string& filePath);

    void save(const std::string& filePath, const float zoomFactor);



private:
    TFDesignViewerUIController();

    virtual ~TFDesignViewerUIController();
};




#endif // TFDESIGNVIEWERUICONTROLLER_H
