#include <iostream>
#include <Eigen/Core>
#include "bce_loss.h"
#include "linear_layer.h"
#include "relu.h"
#include "sigmoid.h"
#include "read_csv.h"

int main() {
    Eigen::Matrix<double,2,2> a;
    a << 1,2,3,4;
    std::cout << a << "\n";
    return 0;
}