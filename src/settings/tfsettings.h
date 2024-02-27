#ifndef TFSETTINGS_H
#define TFSETTINGS_H


#include <device_launch_parameters.h>



namespace settings {


class TFSettings {
public:
    static TFSettings& instance();

    void load();

    void save();

	float pivotSize() const;

	void setPivotSize(float pivotSize);

	float pivotBorderWidth() const;

	void setPivotBorderWidth(float pivotBorderWidth);

    float zoomIncrement() const;

    void setZoomIncrement(float zoomIncrement);

    float baseOpacity() const;

    void setBaseOpacity(float baseOpacity);

    float selectedOpacity() const;

    void setSelectedOpacity(float selectedOpacity);

    float unselectedOpacity() const;

    void setUnselectedOpacity(float unselectedOpacity);

    bool pivotLabelEnabled() const;

	void setPivotLabelEnabled(bool enabled);


private:
    TFSettings();

    virtual ~TFSettings();



private:
	float m_pivotSize;
	float m_pivotBorderWidth;
    float m_zoomIncrement;
    float m_baseOpacity;
    float m_selectedOpacity;
    float m_unselectedOpacity;
    bool m_pivotLabelEnabled;
};



}



#endif
