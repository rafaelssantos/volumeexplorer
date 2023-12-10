#ifndef PIVOT_H
#define PIVOT_H

#include <vector>
#include <set>
#include "selectedtype.h"
#include "pivotui.h"



namespace transfer_function {
class Cluster;
}



namespace transfer_function {


class Pivot {
public:
    Pivot();

    virtual ~Pivot();

    std::vector<int>* voxelIndices() const;

    void setColor(const float4& color);

    void setColor(float red, float green, float blue, float opacity = 1.0f);

    float4 color() const;

    void reset();

	void select(float opacity);

	void unselect(float opacity);

    SelectedType selectedType() const;

    void setCluster(Cluster* cluster);

    Cluster* cluster() const;

	void setUI(PivotUI *ui);

    PivotUI *ui() const;

    std::set<Pivot*>* group() const;

    void setGroup(std::set<Pivot*>* group);


private:
    std::vector<int>* m_voxelIndices;
    float m_defaultOpacity;
    SelectedType m_selectedType;
    Cluster* m_cluster;
    PivotUI *m_ui;
    std::set<Pivot*>* m_group;
};


}

#endif // PIVOT_H
