# Volume Explorer (VEx)

A tool for advanced volume visualization with a focus on multidimensional transfer function design for Direct Volume Rendering (DVR).



## Description
VEx is an experimental tool designed to simplify volume interaction. This tool implements [Santos (2018)](https://repositorio.unesp.br/items/5d693752-868f-4670-aa80-5e2180469e3b) approach, that combines [FastMap](https://dl.acm.org/doi/pdf/10.1145/223784.223812), [DBSCAN](https://pure.tue.nl/ws/portalfiles/portal/46941219/760643-1.pdf), and [Sparse Spatial Selection](https://lbd.udc.es/Repository/Publications/Drafts/SpaSelofSpa.pdf) algorithms to enable comprehensive volume feature exploration at a low computational cost.


## Algorithms
- [Gunawan's DBSCAN](https://pure.tue.nl/ws/portalfiles/portal/46941219/760643-1.pdf). Utilizes both an enhanced version based on Gunawan's work for effective fast DBSCAN on a 2D space.
- [FastMap](https://dl.acm.org/doi/pdf/10.1145/223784.223812). Implements FastMap algorithm for dimensionality reduction.
- [Ray Casting](https://sci-hub.se/10.1109/38.511). Utilizes Ray Casting for efficient volume rendering.
- [Sparse Spatial Selection](https://lbd.udc.es/Repository/Publications/Drafts/SpaSelofSpa.pdf). Applies SSS algorithm for produce pivos and subfeature classification.


## Key features:
- Multidimensional transfer functions.
- Volume feature exploration in 2D Spaces.
- Clustering based approach to assist volume feature classification.


## Sytem Requirements 
- GNU/Linux with support for CUDA C/C++ and Qt environments.
- C++17 compiler.
- CUDA C/C++ Development Toolkit version 11 or later.
- OpenCV library version 4.0 or later.
- Qt Framework version 6.0 or later.
### Dependencies to install
In addition to the CUDA C/C++ Development Toolkit and Qt Frameworks, it is necessary to install some dependencies. 

OpenCV modules:
- (calib3D module) Camera calibration and 3D reconstruction 
- (dnn module) Deep Neural Networks
- (flann module) FLANN
- (highgui module) High-level GUI
- (imgcodecs module) Imgcodecs
- (objdetect module) Object Detection
- (photo module) Computational photography
- (stitching module) Images stitching
- (video module) Video analysis 

OpenGL modules:
- (GLUT library) OpenGL Utility Toolkit.

All OpenCV dependencies can be installed using the following commands (for UBUNTU or other DEBIAN-based distributions):
```
sudo apt install libopencv-calib3d-dev 
sudo apt install libopencv-dnn-dev
sudo apt install libopencv-flann-dev
sudo apt install libopencv-highgui-dev
sudo apt install libopencv-imgcodecs-dev
sudo apt install libopencv-objdetect-dev
sudo apt install libopencv-photo-dev
sudo apt install libopencv-stitching-dev
sudo apt install libopencv-video-dev
```

All OpenGL dependencies can be installed using the following commands (for UBUNTU or other DEBIAN-based distributions):
```
sudo apt install freeglut3-dev
```

