#ifndef RELU
#define RELU
#include <Eigen/Core>

class Relu{
    public:
        Relu(int w, int h);
        Eigen::MatrixXd forward(Eigen::MatrixXd input);
        void backward(Eigen::MatrixXd grad_input);
    private:
        Eigen::MatrixXd _input;
};

#endif
