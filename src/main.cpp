#include <vector>
#include <model.h>
#include "read_csv.h"

int main() {
    Eigen::Matrix<double,2,2> a;
    a << 1,2,3,4;
    std::cout << a << "\n";
    //Linear_Layer layer(5,2);
     std::vector<fcn_operations*> model;
    model.push_back(new Linear_Layer(5,2));
    model.push_back(new Relu());
    model.push_back(new Sigmoid());
    return 0;
}