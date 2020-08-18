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
            input(i,0) = 1/(1+std::exp(-input(i,0)));
        }
        *_sigmoid = input;
        return input;
    }
    Eigen::MatrixXd Sigmoid::backward(Eigen::MatrixXd &grad_matrix){
     return (_sigmoid->array()*(1-_sigmoid->array())*grad_matrix.array()).matrix();
    }
    Eigen::MatrixXd Sigmoid::getPredictions() {return *_sigmoid;}