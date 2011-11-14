#ifndef MOSTIMAGE_H
#define MOSTIMAGE_H

#include "basic_4dimage.h"
#include "basic_landmark.h"
#include "../../../v3d/v3d_main/v3d/v3d_core.h"
#include "v3d_interface.h"
#include "../../../v3d/v3d_main/neuron_editing/v_neuronswc.h"
#include "../../../v3d/v3d_main/neuron_editing/neuron_format_converter.h"

#include "voxelcluster.h"
#include "tools.h"

// some constant threshold
#define MinRadius 1.5
#define MaxRadius 50
#define InitThreshold 20

// include rayburst sampling
extern "C" {
#include "srb.h"
}

class MOSTImage : public Image4DSimple
{
public:
    MOSTImage();
    ~MOSTImage();

    bool isVisted(const LocationSimple &loc);
    V_NeuronSWC trace_single_seed( const LocationSimple &seed );
    NeuronTree trace_seed_list(const LandmarkList &seedList, QVector<bool> &visited_cur);

private:
    int getAdaptiveThreshold( const V_NeuronSWC_unit &pivot, const float &radius );
    V_NeuronSWC_unit createNode(VoxelCluster &conCom, const V_NeuronSWC_unit &preNode, const double &preSize);
    float getRayburstRadius( V_NeuronSWC_unit &center, const bool &force, const int &rayburstThreshold );
    V_NeuronSWC_unit recenter( V_NeuronSWC_unit &center , const int &threshold);
    bool regionGrowInSphere_V2 (const V_NeuronSWC_unit &pivot, const float &radius, V_NeuronSWC_unit &seed, VoxelCluster &clt, const int &threshold);
    VoxelCluster findUnvisitedNeighbor(VoxelCluster &clt );
    VoxelCluster voxelScooping (VoxelCluster &clt, const V_NeuronSWC_unit &node, const float &scoopingDistance, const int &threshold);
    VoxelCluster voxelScooping_V2 ( const V_NeuronSWC_unit &node, const float &scoopingDistance, const int &threshold );

    //varibles
    QVector < bool >  visited;
    LocationSimple seed;
    V_NeuronSWC swc;
    V_NeuronSWC_unit swcUnitTmp;
    NeuronTree vt;
};

#endif // MOSTIMAGE_H
