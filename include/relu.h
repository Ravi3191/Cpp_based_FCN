#ifndef RELU
#define RELU

#include <Eigen/Core>
#include <iostream>
#include <fcn_operations.h>

class Relu : public fcn_operations{
    public:
        //Relu(int w, int h);
        Relu(){}
        Eigen::MatrixXd forward(Eigen::MatrixXd &input);
        Eigen::MatrixXd backward(Eigen::MatrixXd &grad_input);
        ~Relu();
        Relu (const Relu&) = delete;
        Relu& operator= (const Relu&) = delete;
        Relu (Relu &&layer); //move constructor
        Relu &operator=(Relu &&layer); //move assignment
    private:
        Eigen::MatrixXd *_input = new Eigen::MatrixXd;
};

#endif
