#ifndef LINEAR_LAYER
#define LINEAR_LAYER

#include <iostream>
#include <Eigen/Core>
#include <fcn_operations.h>
#include <math.h>

class Linear_Layer : public fcn_operations{

public:
    Linear_Layer(int input_channels, int output_channels);
    Eigen::MatrixXd forward(Eigen::MatrixXd &input);
    Eigen::MatrixXd backward(Eigen::MatrixXd &grad_output);
private:

    Eigen::MatrixXd _weights,_bias,_input, _grad_input, _grad_bias, _grad_weights;
};

#endif
