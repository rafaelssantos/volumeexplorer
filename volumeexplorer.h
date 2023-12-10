#ifndef VOLUMEEXPLORER_H
#define VOLUMEEXPLORER_H

#include <cstddef>
#include <string>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <GL/gl.h>
#include "volume/volume.cuh"
#include "transfer_function/transferfunction.cuh"
#include "transfer_function/tfdesigner.h"
#include "attribute/attributetype.h"
#include "graphics_utils/zoom.h"
#include "graphics_utils/rotationaxis.h"
#include "graphics_utils/rotatationsense.h"




class VolumeExplorer {
public:
    static VolumeExplorer &instance();

    std::string loadDataset(const std::list<std::string>& filesPath, float x, float y, float z);

    void selectAttributes(const std::set<attribute::AttributeType>& attributes, int mask, std::string filePath);

    void render(unsigned width, unsigned height) const;

	void registerGlPBOAsCudaResource(GLuint pbo) const;

	void unregisterGlPBOAsCudaResource() const;

    void zoom(graphics_utils::Zoom zoom) const;

    void rotate(graphics_utils::RotationAxis axis, graphics_utils::RotationSense sense) const;

	void resetViewer() const;

    const std::set<attribute::AttributeType>& availableAttributes() const;

    bool isDatasetLoaded() const;

	const volume::Volume& volume() const;


private:
    VolumeExplorer();

    virtual ~VolumeExplorer();

    volume::Volume *m_hostVolume;
    volume::Volume *m_devVolume;
    transfer_function::TransferFunction *m_hostTransferFunc;
    transfer_function::TransferFunction *m_devTransferFunc;


private:
    VolumeExplorer(const VolumeExplorer&) = delete;
    void operator=(const VolumeExplorer&) = delete;
};


#endif // VOLUMEEXPLORER_H
