#ifndef SIGMOID
#define SIGMOID

#include <iostream>
#include <Eigen/Core>
#include <math.h>
#include <fcn_operations.h>

class Sigmoid : public fcn_operations{
    public:
        Eigen::MatrixXd forward(Eigen::MatrixXd &input);
        Eigen::MatrixXd backward(Eigen::MatrixXd &grad_matrix);
        Eigen::MatrixXd getPredictions();
    private:
        int _size;
        Eigen::MatrixXd _sigmoid;
};



#endif
