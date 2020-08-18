#ifndef SIGMOID
#define SIGMOID

#include <iostream>
#include <Eigen/Core>
#include <math.h>
#include <fcn_operations.h>

class Sigmoid : public fcn_operations{
    public:
        Sigmoid(){}
        Eigen::MatrixXd forward(Eigen::MatrixXd &input);
        Eigen::MatrixXd backward(Eigen::MatrixXd &grad_matrix);
        Eigen::MatrixXd getPredictions();
        ~Sigmoid();
        Sigmoid (const Sigmoid&) = delete;
        Sigmoid& operator= (const Sigmoid&) = delete;
        Sigmoid (Sigmoid &&layer); //move constructor
        Sigmoid &operator=(Sigmoid &&layer); //move assignment
    private:
        int _size;
        Eigen::MatrixXd *_sigmoid = new Eigen::MatrixXd;
};

#endif
