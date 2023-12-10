# Volume Explorer (VEx)

A volume visualization tool for multidimensional transfer function design in Direct Volume Rendering (DVR).


## Description
VEx is an experimental tool with simplify volume interaction. This tool implements [Santos (2018)](https://repositorio.unesp.br/items/5d693752-868f-4670-aa80-5e2180469e3b) approach that combines [FastMap](https://dl.acm.org/doi/pdf/10.1145/223784.223812), [DBSCAN](https://pure.tue.nl/ws/portalfiles/portal/46941219/760643-1.pdf), and [Sparse Spatial Selection](https://lbd.udc.es/Repository/Publications/Drafts/SpaSelofSpa.pdf) algorithms for a comprehensive and a low computational cost volume feature exploration space.


## Algorithms
- [DBSCAN](https://cdn.aaai.org/KDD/1996/KDD96-037.pdf) and [Gunawan's DBSCAN]https://pure.tue.nl/ws/portalfiles/portal/46941219/760643-1.pdf)
- [FastMap](https://dl.acm.org/doi/pdf/10.1145/223784.223812)
- [Ray Casting]
- [Sparse Spatial Selection](https://lbd.udc.es/Repository/Publications/Drafts/SpaSelofSpa.pdf) 


## Key features:
- Multidimensional transfer functions.
- Volume feature exploration on a simplified 2D space.
- Clustering based approach to assist volume exploration.


## Sytem Requirements 
- Linux distro with support of required libraries and frameworks .
- C++17.
- CUDA toolkit 11 or later.
- Qt Framework 6.0  or later.
- OpenCV 4.0 or later.
