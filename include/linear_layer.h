#ifndef LINEAR_LAYER
#define LINEAR_LAYER

#include <iostream>
#include <Eigen/Dense>
#include <math>

class Linear_Layer{

public:
    Linear_Layer(int input_channels, int output_channels);
    Eigen::MatrixXd forward(EIgen::MatrixXd input);
    void backward(Eigen::MatrixXd grad_output);
private:

    Eigen::MatrixXd _weights,_bias,_input,grad_input,grad_bias,grad_weights;

};

#endif