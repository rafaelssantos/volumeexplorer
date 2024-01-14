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
- Linux distribution with required library and framework support.
- C++17.
- CUDA toolkit 11 or later.
- OpenCV 4.0 or later.
- Qt Framework 6.0 or later.
### Package to install
Besides the CUDA C/C++ Developement Tookit and Qt Frameworks, it is required to install the following depenencies:
- Imgcodecs OpenCV module.
- High-level GUI OpenCV module.
- FLANN OpenCV module.
- OpenGL Utility Toolkit (GLUT).
All dependencies can be install as the following codes:
```
$ sudo apt install freeglut3-dev
$
$
$

```

