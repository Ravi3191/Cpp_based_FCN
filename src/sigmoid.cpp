#include "sigmoid.h"

    Eigen::MatrixXd farward(Eigen::MatrixXd input){
        for(int i=0; i<input.rows(); i++){
            input(i,0) = 1/(1+std::expf(-input(i,0)));
        }
        return input;
    }
    void backward(Eigen::MatrixXd grad_matrix){
        
    }