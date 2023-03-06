#include <cmath>
#include <eigen3/Eigen/Geometry>
#include <iostream>

class Transformation {
   public:
    Eigen::MatrixXd transformMat;
    Transformation() {
        C1(4, 1), C2(4, 1), C3(4, 1), A(4, 4), transformMat(4, 4);
    }

   private:
    Eigen::MatrixXd C1, C2, C3, A;

    double phi, psi, theta;

    // std::vector<Eigen::Vector3d> ptsA, ptsB;
    // Eigen::Vector3d ptsA[6], ptsB[6];
};