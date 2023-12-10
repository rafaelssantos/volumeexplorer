#include "pivot.h"

#include "pivotui.h"
#include "transfer_function/tfdesigner.h"



using namespace std;
using namespace transfer_function;





Pivot::Pivot() {
	m_voxelIndices = new vector<int>();
	m_defaultOpacity = 1.0f;
	m_selectedType = SelectedType::NONE;
	m_cluster = nullptr;
	m_ui = nullptr;
	m_group = nullptr;
}





Pivot::~Pivot() {
	delete m_voxelIndices;
	delete m_group;
}




std::vector<int> *Pivot::voxelIndices() const {
	return m_voxelIndices;
}





void Pivot::setColor(const float4& color) {
	if(m_selectedType == SelectedType::NONE){
		m_defaultOpacity = color.w;
		m_ui->setColor(color);
	}
	else{
		float curOpacity = m_ui->color().w;
		m_ui->setColor(color);
		m_ui->setColor(m_ui->color().x, m_ui->color().y, m_ui->color().z, curOpacity);
	}


	for(auto v = m_voxelIndices->begin(); v != m_voxelIndices->end(); v++) {
		TFDesigner::instance().setVoxelColor(*v, m_ui->color());
	}
}





void Pivot::setColor(float red, float green, float blue, float opacity) {
	if(m_selectedType == SelectedType::NONE){
		m_defaultOpacity = opacity;
		m_ui->setColor(red, green, blue, opacity);
	}
	else{
		m_ui->setColor(red, green, blue, m_ui->color().w);
	}

	for(auto v = m_voxelIndices->begin(); v != m_voxelIndices->end(); v++) {
		TFDesigner::instance().setVoxelColor(*v, m_ui->color());
	}
}





 float4 Pivot::color() const {
	float4 color = m_ui->color();
	color.w = m_defaultOpacity;
	return color;
}





void Pivot::reset() {
	m_ui->setColor(m_ui->color().x, m_ui->color().y, m_ui->color().z, m_defaultOpacity);
	m_ui->setUnselectedOpacity(m_defaultOpacity);
	m_selectedType = SelectedType::NONE;

	for(auto v = m_voxelIndices->begin(); v != m_voxelIndices->end(); v++) {
		TFDesigner::instance().setVoxelColor(*v, m_ui->color());
	}
}




void Pivot::select(float opacity) {
	m_ui->setColor(m_ui->color().x, m_ui->color().y, m_ui->color().z, opacity);
    m_ui->setUnselectedOpacity(opacity);
	m_selectedType = SelectedType::SELECTED;

	for(auto v = m_voxelIndices->begin(); v != m_voxelIndices->end(); v++) {
		TFDesigner::instance().setVoxelColor(*v, m_ui->color());
	}
}





void Pivot::unselect(float opacity) {
	m_ui->setColor(m_ui->color().x, m_ui->color().y, m_ui->color().z, opacity);
    m_ui->setUnselectedOpacity(opacity);
	m_selectedType = SelectedType::UNSELECTED;

	for(auto v = m_voxelIndices->begin(); v != m_voxelIndices->end(); v++) {
		TFDesigner::instance().setVoxelColor(*v, m_ui->color());
	}
}





SelectedType Pivot::selectedType() const {
	return m_selectedType;
}




void Pivot::setCluster(Cluster* cluster) {
	m_cluster = cluster;
}




Cluster* Pivot::cluster() const {
	return m_cluster;
}



void Pivot::setUI(PivotUI* ui) {
	m_ui = ui;
}




PivotUI* Pivot::ui() const {
	return m_ui;
}



std::set<Pivot *> *Pivot::group() const {
	return m_group;
}




void Pivot::setGroup(std::set<Pivot*>* group) {
	m_group = group;
}
