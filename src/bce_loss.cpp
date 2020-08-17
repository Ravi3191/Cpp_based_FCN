#include "bce_loss.h"

Bce_Loss::Bce_Loss() : _loss{0}, _size{0} {}

void Bce_Loss::forward(const Eigen::MatrixXd &ground_truth, Eigen::MatrixXd &predictions){
    _size = ground_truth.rows();
    _gt = ground_truth;
    _loss_vector.resize(_size,1);
    for(int i=0; i < ground_truth.rows(); i++){
        if(ground_truth(i,0) == 0){
            if(predictions(i,0) == 0.0){
                predictions(i,0) += 0.00001;
            }
            _loss_vector(i,0) = std::log(predictions(i,0)); 
            _loss += _loss_vector(i,0);
        }
        else{
            if(predictions(i,0) == 1.0){
                predictions(i,0) -= 0.00001;
            }
            _loss_vector(i,0) = std::log(1-predictions(i,0));
            _loss += _loss_vector(i,0);
        }
    }
    _loss = -_loss/_size;
}

Eigen::MatrixXd Bce_Loss::backward(){
    Eigen::MatrixXd grad;
    grad.resize(_size,1);
    for(int i = 0; i<_size; i++){
        if(_gt(i,0)==1){
            grad(i,0) = -1/_loss_vector(i,0);
        }
        if(_gt(i,0)==0){
            grad(i,0) = -1/(1-_loss_vector(i,0));
        }
    }  
    return grad;
}

double Bce_Loss::get_loss() {return _loss;}