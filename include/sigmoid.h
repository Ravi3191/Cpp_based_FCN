#ifndef SIGMOID
#define SIGMOID

#include <iostream>
#include <Eigen/Core>
#include <math.h>

class Sigmoid{
    public:
        Eigen::MatrixXd forward(Eigen::MatrixXd input);
        void backward(Eigen::MatrixXd grad_matrix);
    private:
        int _size;
        Eigen::MatrixXd _sigmoid,_output;

};



#endif
