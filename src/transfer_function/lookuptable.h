#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H


#include "transfer_function/transferfunction.cuh"
#include "selectionmode.h"
#include "pivot.h"
#include "pivotui.h"
#include "cluster.h"




namespace transfer_function {

class TFDesigner;
class TFDesignLoader;

}




namespace transfer_function {


class LookUpTable {
    friend class transfer_function::TFDesigner;



public:
    LookUpTable(transfer_function::TransferFunction *transferFunction);

    virtual ~LookUpTable();

    void setPivotColor(int index, const float4& color);

    void setClusterColor(int index, const float4& color);

    void setSelectedPivotsColor(const float4& color);

    void setSelectedCluster(int index, float opacity, float unselectedOpacity);

    void setSelectedAt(SelectionMode selectionMode, int pivotIndex, float opacity, float unselectedOpacity);

    void setUnselectedAt(SelectionMode selectionMode, int pivotIndex, float opacity);

    void unselectAll();

    void groupSelectedPivots();

    void ungroupSelectedPivots();

    void setSelectedGroup(int index, float opacity, float unselectedOpacity);

	void setSelectedPivot(int index, float opacity, float unselectedOpacity);



private:
    transfer_function::TransferFunction* m_transferFunction;

    std::vector<Cluster*> m_clusters;
    std::vector<Pivot*> m_pivots;
    std::set<Pivot*> m_selectedPivots;
	std::set<std::set<Pivot*>*> m_groups;


    bool isAnyPivotSelected() const;
};


}


#endif // LOOKUPTABLE_H
