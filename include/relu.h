#ifndef RELU
#define RELU

#include <Eigen/Core>
#include <fcn_operations.h>

class Relu : public fcn_operations{
    public:
        //Relu(int w, int h);
        Eigen::MatrixXd forward(Eigen::MatrixXd &input);
        Eigen::MatrixXd backward(Eigen::MatrixXd &grad_input);
    private:
        Eigen::MatrixXd _input;
};

#endif
