#ifndef RELU
#define RELU
#include <Eigen/Dense>

class Relu{
    public:
        Relu(int w, int h);
        Eigen::MatrixXd forward();
        void backward(Eigen::MatrixXd grad_input);
    private:
        Eigen::MatrixXd _input;
};

#endif