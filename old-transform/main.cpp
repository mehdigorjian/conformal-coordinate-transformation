#include <cmath>
#include <eigen3/Eigen/Geometry>
#include <iostream>
// #include <vector>

void calculateA(Eigen::MatrixXd& A, Eigen::Vector3d* ptsA, int numOfptsAirs) {
    for (int i = 0; i < numOfptsAirs; i++) {
        A(0, 0) += ptsA[i][0] * ptsA[i][0];
        A(0, 1) += ptsA[i][0] * ptsA[i][1];
        A(0, 2) += ptsA[i][0] * ptsA[i][2];
        A(0, 3) += ptsA[i][0];
        A(1, 0) += ptsA[i][0] * ptsA[i][1];
        A(1, 1) += ptsA[i][1] * ptsA[i][1];
        A(1, 2) += ptsA[i][1] * ptsA[i][2];
        A(1, 3) += ptsA[i][1];
        A(2, 0) += ptsA[i][0] * ptsA[i][2];
        A(2, 1) += ptsA[i][1] * ptsA[i][2];
        A(2, 2) += ptsA[i][2] * ptsA[i][2];
        A(2, 3) += ptsA[i][2];
        A(3, 0) += ptsA[i][0];
        A(3, 1) += ptsA[i][1];
        A(3, 2) += ptsA[i][2];
    }
    A(3, 3) = (double)numOfptsAirs;
}

void calculateC1(Eigen::MatrixXd& C1, Eigen::Vector3d* ptsA, Eigen::Vector3d* ptsB, int numOfptsAirs) {
    for (int i = 0; i < numOfptsAirs; i++) {
        C1(0, 0) += ptsB[i][0] * ptsA[i][0];
        C1(1, 0) += ptsB[i][0] * ptsA[i][1];
        C1(2, 0) += ptsB[i][0] * ptsA[i][2];
        C1(3, 0) += ptsB[i][0];
    }
}

void calculateC2(Eigen::MatrixXd& C2, Eigen::Vector3d* ptsA, Eigen::Vector3d* ptsB, int numOfptsAirs) {
    for (int i = 0; i < numOfptsAirs; i++) {
        C2(0, 0) += ptsB[i][1] * ptsA[i][0];
        C2(1, 0) += ptsB[i][1] * ptsA[i][1];
        C2(2, 0) += ptsB[i][1] * ptsA[i][2];
        C2(3, 0) += ptsB[i][1];
    }
}

void calculateC3(Eigen::MatrixXd& C3, Eigen::Vector3d* ptsA, Eigen::Vector3d* ptsB, int numOfptsAirs) {
    for (int i = 0; i < numOfptsAirs; i++) {
        C3(0, 0) += ptsB[i][2] * ptsA[i][0];
        C3(1, 0) += ptsB[i][2] * ptsA[i][1];
        C3(2, 0) += ptsB[i][2] * ptsA[i][2];
        C3(3, 0) += ptsB[i][2];
    }
}

void calculateTransformMatrix(Eigen::MatrixXd& transformMat, double& phi, double& psi, double& theta, const Eigen::MatrixXd& A, const Eigen::MatrixXd& C1, const Eigen::MatrixXd& C2, const Eigen::MatrixXd& C3) {
    Eigen::MatrixXd row1(4, 1), row2(4, 1), row3(4, 1), temp(4, 1);
    row1 = A.inverse() * C1;
    row2 = A.inverse() * C2;
    row3 = A.inverse() * C3;

    transformMat(3, 0) = 0.0;
    transformMat(3, 1) = 0.0;
    transformMat(3, 2) = 0.0;
    transformMat(3, 3) = 1.0;

    for (int i = 0; i < 3; i++) {
        if (i == 0) temp = row1;
        if (i == 1) temp = row2;
        if (i == 2) temp = row3;
        for (int j = 0; j < 4; j++) {
            transformMat(i, j) = temp(j, 0);
        }
    }
    phi = std::atan2(transformMat(1, 2), transformMat(2, 2));
    psi = std::atan2(transformMat(0, 1), transformMat(0, 0));
    theta = std::atan2(-transformMat(0, 2), transformMat(0, 1) / std::sin(psi));
}

int main(int argc, char* argv[]) {
    Eigen::Vector3d p1c, p2c, p3c, p4c, p5c, p6c,
        p1h, p2h, p3h, p4h, p5h, p6h;

    p1c = {0.5449, 0.1955, 0.9227};
    p2c = {0.6862, 0.7202, 0.8004};
    p3c = {0.8936, 0.7218, 0.2859};
    p4c = {0.0548, 0.8778, 0.5437};
    p5c = {0.3037, 0.5824, 0.9848};
    p6c = {0.0462, 0.0707, 0.7157};

    p1h = {2.5144, 7.0691, 1.9754};
    p2h = {2.8292, 7.4454, 2.2224};
    p3h = {3.3518, 7.3060, 2.1198};
    p4h = {2.8392, 7.8455, 1.6229};
    p5h = {2.4901, 7.5449, 1.9518};
    p6h = {2.4273, 7.1354, 1.4349};

    // std::vector<Eigen::Vector3d> ptsA, ptsB;
    // Eigen::Vector3d ptsA[6], ptsB[6];
    Eigen::Vector3d ptsA[] = {p1c, p2c, p3c, p4c, p5c, p6c};
    Eigen::Vector3d ptsB[] = {p1h, p2h, p3h, p4h, p5h, p6h};

    // Eigen::MatrixXd A(4, 4);
    Eigen::MatrixXd C1(4, 1), C2(4, 1), C3(4, 1);
    Eigen::MatrixXd A(4, 4), transformMat(4, 4);
    double phi, psi, theta;
    int pairsNum = 6;

    std::cout << "-----------------------------A" << std::endl;

    calculateA(A, ptsA, pairsNum);
    std::cout << A << std::endl;

    std::cout << "-----------------------------C1" << std::endl;

    calculateC1(C1, ptsA, ptsB, pairsNum);
    std::cout << C1 << std::endl;

    std::cout << "-----------------------------C2" << std::endl;

    calculateC2(C2, ptsA, ptsB, pairsNum);
    std::cout << C2 << std::endl;

    std::cout << "-----------------------------C3" << std::endl;

    calculateC3(C3, ptsA, ptsB, pairsNum);
    std::cout << C3 << std::endl;

    std::cout << "-----------------------------T" << std::endl;

    calculateTransformMatrix(transformMat, phi, psi, theta, A, C1, C2, C3);
    std::cout << transformMat << std::endl;

    std::cout << "-----------------------------" << std::endl;

    std::cout << "phi : " << phi << " psi : " << psi << " theta : " << theta << std::endl;

    std::cout << "-----------------------------" << std::endl;

    return 0;
}