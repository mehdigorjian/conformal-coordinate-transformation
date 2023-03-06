#include <cmath>
#include <eigen3/Eigen/Geometry>
#include <iostream>

Eigen::Vector3d normalVector(const Eigen::Vector3d& p1, const Eigen::Vector3d& p2, const Eigen::Vector3d& p3) {
    Eigen::Vector3d n((p2[1] - p1[1]) * (p3[2] - p1[2]) - (p3[1] - p1[1]) * (p2[2] - p1[2]),
                      (p3[0] - p1[0]) * (p2[2] - p1[2]) - (p2[0] - p1[0]) * (p3[2] - p1[2]),
                      (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p3[0] - p1[0]) * (p2[1] - p1[1]));

    return n;
}

void tilt_azimuth(Eigen::Vector3d normal, double& tilt, double& azimuth) {
    // double t = normal[2] / std::sqrt(normal[0] * normal[0] + normal[1] * normal[1]);
    tilt = std::atan(normal[2] / std::sqrt(normal[0] * normal[0] + normal[1] * normal[1])) + 90;
    azimuth = std::atan(normal[0] / normal[1]);
}

Eigen::Vector3d swing(Eigen::Vector3d azimuth_control_hapt, Eigen::Vector3d azimuth_arbitary_opti) {
    return azimuth_control_hapt - azimuth_arbitary_opti;
}

void coorIndividualRotMat(Eigen::Matrix3d& mat, double a, double t, double s) {
    mat(1, 1) = -std::cos(a) * std::cos(s) - std::sin(a) * std::cos(t) * std::sin(s);
    mat(1, 2) = std::sin(a) * std::cos(s) - std::cos(a) * std::cos(t) * std::sin(s);
    mat(1, 3) = -std::sin(t) * std::sin(s);

    mat(2, 1) = std::cos(a) * std::sin(s) - std::sin(a) * std::cos(t) * std::cos(s);
    mat(2, 2) = -std::sin(a) * std::sin(s) - std::cos(a) * std::cos(t) * std::cos(s);
    mat(2, 3) = -std::sin(t) * std::cos(s);

    mat(3, 1) = -std::sin(a) * std::sin(t);
    mat(3, 2) = -std::cos(a) * std::sin(t);
    mat(3, 3) = std::cos(t);
}

int main(int argc, char* argv[]) {
    Eigen::Vector3d p1c, p2c, p3c, p1h, p2h, p3h;

    return 0;
}