#include "sigmoid.h"

    Eigen::MatrixXd Sigmoid::forward(Eigen::MatrixXd input){
        for(int i=0; i<input.rows(); i++){
            input(i,0) = 1/(1+std::exp(-input(i,0)));
        }
        _sigmoid = input;
        return input;
    }
    void Sigmoid::backward(Eigen::MatrixXd grad_matrix){
     _output = _sigmoid.array()*(1-_sigmoid.array())*grad_matrix.array();   
    }