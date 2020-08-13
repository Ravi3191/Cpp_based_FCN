#ifndef SIGMOID
#define SIGMOID

#include <iostream>
#include <Eigen/Dense>
#include <math>

class Sigmoid{
    public:
        Eigen::MatrixXd farward(Eigen::MatrixXd input);
        void backward(Eigen::MatrixXd grad_matrix);
    private:
        int _size;

};



#endif