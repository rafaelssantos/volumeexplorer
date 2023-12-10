#include "tfsettings.h"


#include <QSettings>



using namespace settings;





TFSettings::TFSettings() {
	m_pivotSize = 10.0f;
	m_pivotBorderWidth = 3.0f;
    m_baseOpacity = 0.5f;
	m_zoomIncrement = 0.05f;
	m_unselectedOpacity = 0.0f;
    m_selectedOpacity = 0.5f;
    m_pivotLabelEnabled = false;
}





TFSettings::~TFSettings() {
}



bool TFSettings::pivotLabelEnabled() const{
    return m_pivotLabelEnabled;
}



void TFSettings::setPivotLabelEnabled(bool enabled){
    m_pivotLabelEnabled = enabled;
}





TFSettings& TFSettings::instance() {
    static TFSettings instance;

    return instance;
}





void TFSettings::load() {
    QSettings settings("volumeExplorer", "TFSettings");


	m_pivotSize = settings.value("pivotSize", 10.0f).toFloat();
	m_pivotBorderWidth = settings.value("pivotBorderWidth", 3.0f).toFloat();
    m_baseOpacity = settings.value("baseOpacity", 0.5f).toFloat();
	m_zoomIncrement = settings.value("zoomIncrement", 0.05f).toFloat();
	m_selectedOpacity = settings.value("selectedOpacity", 0.5f).toFloat();
	m_unselectedOpacity = settings.value("unselectedOpacity", 0.0f).toFloat();
    m_pivotLabelEnabled = settings.value("pivotLabelEnabled", false).toBool();

    settings.sync();
}





void TFSettings::save() {
    QSettings settings("volumeExplorer", "TFSettings");

	settings.setValue("pivotSize", m_pivotSize);
	settings.setValue("pivotBorderWidth", m_pivotBorderWidth);
    settings.setValue("baseOpacity", m_baseOpacity);
    settings.setValue("zoomIncrement", m_zoomIncrement);
    settings.setValue("selectedOpacity", m_selectedOpacity);
    settings.setValue("unselectedOpacity", m_unselectedOpacity);
    settings.setValue("pivotLabelEnabled", m_pivotLabelEnabled);

    settings.sync();
}





float TFSettings::pivotSize() const {
	return m_pivotSize;
}




void TFSettings::setPivotSize(float pivotSize) {
	m_pivotSize = pivotSize;
}




float TFSettings::pivotBorderWidth() const {
	return m_pivotBorderWidth;
}




void TFSettings::setPivotBorderWidth(float pivotBorderWidth) {
	m_pivotBorderWidth = pivotBorderWidth;
}




float TFSettings::zoomIncrement() const {
    return m_zoomIncrement;
}




void TFSettings::setZoomIncrement(float zoomIncrement) {
    m_zoomIncrement = zoomIncrement;
}




float TFSettings::baseOpacity() const {
    return m_baseOpacity;
}




void TFSettings::setBaseOpacity(float baseOpacity) {
    m_baseOpacity = baseOpacity;
}




float TFSettings::selectedOpacity() const {
    return m_selectedOpacity;
}





void TFSettings::setSelectedOpacity(float selectedOpacity) {
    m_selectedOpacity = selectedOpacity;
}




float TFSettings::unselectedOpacity() const {
    return m_unselectedOpacity;
}





void TFSettings::setUnselectedOpacity(float unselectedOpacity) {
    m_unselectedOpacity = unselectedOpacity;
}
