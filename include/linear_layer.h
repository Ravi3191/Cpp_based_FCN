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
    ~Linear_Layer();
    Linear_Layer (const Linear_Layer&) = delete;
    Linear_Layer& operator= (const Linear_Layer&) = delete;
    Linear_Layer (Linear_Layer &&layer); //move constructor
    Linear_Layer &operator=(Linear_Layer &&layer); //move assignment
private:

    Eigen::MatrixXd *_weights = new Eigen::MatrixXd;
    Eigen::MatrixXd *_bias = new Eigen::MatrixXd;
    Eigen::MatrixXd *_input = new Eigen::MatrixXd;
    Eigen::MatrixXd *_grad_input = new Eigen::MatrixXd;
    Eigen::MatrixXd *_grad_bias = new Eigen::MatrixXd;
    Eigen::MatrixXd *_grad_weights = new Eigen::MatrixXd;
};

#endif
