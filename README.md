## Conformal Coordinate Transformation

Creating transformation matrix and giving MSE error based on collecting arbitrary number of points coordinated in two different coordinate system. <br/>

pt1, pt2, ..., ptN <br/>
ptsA: points coordinates in coordinate system A <br/>
ptsB: points coordinates in coordinate system B <br/>
<br/>
Transformation matrix should be a matrix in which: <br/>
B = T * A <br/>
<br/>
To use this package, add Eigen library's path to the makefile and create "coordinateTransform" object. An example added to the main.cpp file. <br/>

Reference: [Automatic Calculation of a Transformation Matrix Between Two Frames](https://ieeexplore.ieee.org/stamp/stamp.jsp?arnumber=8271986&tag=1)