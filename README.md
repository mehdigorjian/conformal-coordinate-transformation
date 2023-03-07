## Conformal Coordinate Transformation

Creating transformation matrix and giving MSE error based on collecting arbitrary number of points coordinated in two different coordinate system.\\

pt1, pt2, ..., ptN
ptsA: points coordinates in coordinate system A
ptsB: points coordinates in coordinate system B

Transformation matrix should be a matrix in which:
B = T * A

To use this package, add Eigen library's path to the makefile and create "coordinateTransform" object. An example added to the main.cpp file.