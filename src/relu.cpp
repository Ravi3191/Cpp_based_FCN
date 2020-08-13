#include "relu.h"


    Relu(int w, int h){
        _input.reshape(w,h);
    }
    Eigen::MatrixXd forward(Eigen::MatrixXd input){
        _input = input;
        input = (input.array()<0).select(0,input);
        return input;
    }
    void backward(Eigen::MatrixXd grad_input){
        grad_input = (_input.array()<0).select(0,grad_input);
    }