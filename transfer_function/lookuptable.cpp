#include "lookuptable.h"

#include <set>

using namespace std;
using namespace transfer_function;





LookUpTable::LookUpTable(TransferFunction* transferFunction) {
    m_transferFunction = transferFunction;
}





LookUpTable::~LookUpTable() {
	for(auto i = 0; i < m_pivots.size(); i++){
        delete m_pivots[i];
		m_pivots[i] = nullptr;
    }

	for(auto i = 0; i < m_clusters.size(); i++){
        delete m_clusters[i];
		m_clusters[i] = nullptr;
    }

	for(auto i = m_groups.begin(); i != m_groups.end(); i++){
		(*i)->clear();
	}

	m_pivots.clear();
	m_clusters.clear();
	m_groups.clear();
}




void LookUpTable::setPivotColor(int index, const float4& color) {
    m_pivots[static_cast<unsigned>(index)]->setColor(color);
}



void LookUpTable::setClusterColor(int index, const float4& color) {
    Cluster* cluster = m_clusters[index];

    for(auto r = cluster->pivots()->begin(); r != cluster->pivots()->end(); r++) {
        (*r)->setColor(color);
    }
}




void LookUpTable::setSelectedPivotsColor(const float4& color) {
    for(auto r = m_selectedPivots.begin(); r != m_selectedPivots.end(); r++){
        (*r)->setColor(color);
    }
}





void LookUpTable::setSelectedCluster(int index, float opacity, float unselectedOpacity) {
    if(!isAnyPivotSelected()){
        for(auto r = m_pivots.begin(); r != m_pivots.end(); r++) {
            (*r)->unselect(unselectedOpacity);
            (*r)->ui()->setSelected(false, true);
        }
    }

    Cluster* cluster = m_clusters.at(index);

    for(auto r = cluster->pivots()->begin(); r != cluster->pivots()->end(); r++) {
        (*r)->select(opacity);
        (*r)->ui()->setSelected(true, true);
        m_selectedPivots.insert(*r);
    }
}



void LookUpTable::setSelectedGroup(int index, float opacity, float unselectedOpacity) {
    if(!isAnyPivotSelected()){
        for(auto r = m_pivots.begin(); r != m_pivots.end(); r++) {
            (*r)->unselect(unselectedOpacity);
            (*r)->ui()->setSelected(false, true);
        }
    }

    auto groupIter = m_groups.begin();
    for(auto i = 0; i < index; i++){
        groupIter++;
    }

	set<Pivot*>* group = *groupIter;

	for(auto r = group->begin(); r != group->end(); r++) {
        (*r)->select(opacity);
        (*r)->ui()->setSelected(true, true);
        m_selectedPivots.insert(*r);
	}
}



void LookUpTable::setSelectedPivot(int index, float opacity, float unselectedOpacity){
	if(!isAnyPivotSelected()){
		for(auto r = m_pivots.begin(); r != m_pivots.end(); r++) {
			(*r)->unselect(unselectedOpacity);
			(*r)->ui()->setSelected(false, true);
		}
	}
	m_pivots[index]->select(opacity);
	m_pivots[index]->ui()->setSelected(true, true);
}






void LookUpTable::setSelectedAt(SelectionMode selectionMode, int pivotIndex, float opacity, float unselectedOpacity) {
    if(!isAnyPivotSelected()){
        for(auto r = m_pivots.begin(); r != m_pivots.end(); r++) {
            (*r)->unselect(unselectedOpacity);
            (*r)->ui()->setSelected(false, true);
        }
    }

    if(selectionMode == SelectionMode::PIVOT) {
		m_pivots[pivotIndex]->select(opacity);
		m_pivots[pivotIndex]->ui()->setSelected(true, true);
		m_selectedPivots.insert(m_pivots[pivotIndex]);
    }
    else if(selectionMode == SelectionMode::CLUSTER) {
		Cluster* cluster = dynamic_cast<Cluster*>(m_pivots[pivotIndex]->cluster());

        for(auto r = cluster->pivots()->begin(); r != cluster->pivots()->end(); r++) {
            (*r)->select(opacity);
            (*r)->ui()->setSelected(true, true);
            m_selectedPivots.insert(*r);
        }
    }
    else if(selectionMode == SelectionMode::GROUP){
		set<Pivot*>* group = m_pivots[pivotIndex]->group();
        if(group == nullptr) {
            setSelectedAt(SelectionMode::PIVOT, pivotIndex, opacity, unselectedOpacity);
        }
        else {
            for(auto r = group->begin(); r != group->end(); r++) {
                (*r)->select(opacity);
                (*r)->ui()->setSelected(true, true);
                m_selectedPivots.insert(*r);
            }
        }
    }
}




void LookUpTable::setUnselectedAt(SelectionMode selectionMode, int pivotIndex, float opacity) {
    if(selectionMode == SelectionMode::PIVOT) {
        m_pivots[static_cast<unsigned>(pivotIndex)]->unselect(opacity);
        m_pivots[static_cast<unsigned>(pivotIndex)]->ui()->setSelected(false, true);
        m_selectedPivots.erase(m_pivots[static_cast<unsigned>(pivotIndex)]);
    }
    else if(selectionMode == SelectionMode::CLUSTER) {
        Cluster* cluster = dynamic_cast<Cluster*>(m_pivots[static_cast<unsigned>(pivotIndex)]->cluster());

        for(auto p = cluster->pivots()->begin(); p != cluster->pivots()->end(); p++) {
            (*p)->unselect(opacity);
            (*p)->ui()->setSelected(false, true);
            m_selectedPivots.erase(*p);
        }
    }
    else if(selectionMode == SelectionMode::GROUP){
        set<Pivot*>* group = m_pivots[static_cast<unsigned>(pivotIndex)]->group();

        if(group == nullptr) {
            setUnselectedAt(SelectionMode::PIVOT, pivotIndex, opacity);
        }
        else {
            for(auto p = group->begin(); p != group->end(); p++) {
                (*p)->unselect(opacity);
                (*p)->ui()->setSelected(false, true);
                m_selectedPivots.erase(*p);
            }
        }
    }

    if(!isAnyPivotSelected()) {
        for(auto r = m_pivots.begin(); r != m_pivots.end(); r++) {
            (*r)->reset();
        }
        m_selectedPivots.clear();
    }
}




void LookUpTable::unselectAll() {
    for(unsigned i = 0; i < m_pivots.size(); i++){
        m_pivots[i]->ui()->setSelected(false, true);
        m_pivots[i]->reset();
    }

    m_selectedPivots.clear();;
}




void LookUpTable::groupSelectedPivots() {
    if(m_selectedPivots.size() > 0){
        set<Pivot*>* group = new set<Pivot*>();

		m_groups.insert(group);

        for (auto i = m_selectedPivots.begin(); i != m_selectedPivots.end(); i++) {

            if((*i)->group() != nullptr){
                (*i)->group()->erase(*i);

                if(group != (*i)->group() && (*i)->group()->empty()){
                    m_groups.erase((*i)->group());
                }
            }

            (*i)->setGroup(group);
            group->insert(*i);
        }
    }
}




void LookUpTable::ungroupSelectedPivots() {
    for (auto i = m_selectedPivots.begin(); i != m_selectedPivots.end(); i++) {
        if((*i)->group() != nullptr){
            (*i)->group()->erase(*i);

            if((*i)->group()->empty()){
                m_groups.erase((*i)->group());
            }
        }

        (*i)->setGroup(nullptr);
    }
}




bool LookUpTable::isAnyPivotSelected() const {
    for(unsigned i = 0; i < m_pivots.size(); i++){
        if(m_pivots.at(i)->selectedType() == SelectedType::SELECTED){
            return true;
        }
    }
    return false;
}
