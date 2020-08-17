#include "sigmoid.h"

    Eigen::MatrixXd Sigmoid::forward(Eigen::MatrixXd &input){
        for(int i=0; i<input.rows(); i++){
            input(i,0) = 1/(1+std::exp(-input(i,0)));
        }
        _sigmoid = input;
        return input;
    }
    Eigen::MatrixXd Sigmoid::backward(Eigen::MatrixXd &grad_matrix){
     return (_sigmoid.array()*(1-_sigmoid.array())*grad_matrix.array()).matrix();
    }
    Eigen::MatrixXd getPredictions() {return _sigmoid;}