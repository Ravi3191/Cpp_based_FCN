#include "sigmoid.h"

    Sigmoid::~Sigmoid(){
        if(_sigmoid != nullptr){
            delete _sigmoid;
            _sigmoid = nullptr;
        }
    }

    Sigmoid::Sigmoid (Sigmoid &&layer){
        _sigmoid = layer._sigmoid;
        layer._sigmoid = nullptr;

    }

    Sigmoid &Sigmoid::operator=(Sigmoid &&layer){
        if(this == &layer){
            return *this;
        }
        delete _sigmoid;
        _sigmoid = new Eigen::MatrixXd(*layer._sigmoid);
        layer._sigmoid = nullptr;

        return *this;
    }

    Eigen::MatrixXd Sigmoid::forward(Eigen::MatrixXd &input){
        for(int i=0; i<input.rows(); i++){
            input(i,0) = 1.0/(1.0+std::exp(-input(i,0)));
        }
        *_sigmoid = input;
        return input;
    }

    Eigen::MatrixXd Sigmoid::backward(Eigen::MatrixXd &grad_matrix){
        Eigen::MatrixXd temp = (_sigmoid->array()*(1-_sigmoid->array())*grad_matrix.array()).matrix();
     return temp;
    }

    Eigen::MatrixXd Sigmoid::getPredictions() {
        Eigen::MatrixXd pred_array = *_sigmoid;
        for (int i = 0; i < pred_array.rows(); i++){
            if(pred_array(i,0) > 0.5) {pred_array(i,0) = 1.0;}
            else pred_array(i,0) = 0.0;
        }
        return pred_array;
    }
    