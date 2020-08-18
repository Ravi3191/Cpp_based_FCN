#include <vector>
#include <model.h>
#include <Eigen/Dense>
#include "read_csv.h"

int main() {
    Model model;
    Eigen::MatrixXd data;
    Eigen::MatrixXd gt;
    data.resize(5,10);
    data.Random();
    gt.resize(5,1);
    gt << 1,1,0,0,1;
    model.train(5,data,gt);
    return 0;
}