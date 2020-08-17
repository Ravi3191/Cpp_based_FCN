#include "relu.h"


    Relu::Relu(int w, int h){
        _input.resize(w,h);
    }
    Eigen::MatrixXd Relu::forward(Eigen::MatrixXd input){
        _input = input;
        input = (input.array()<0).select(0,input);
        return input;
    }
    void Relu::backward(Eigen::MatrixXd grad_input){
        grad_input = (_input.array()<0).select(0,grad_input);
    }