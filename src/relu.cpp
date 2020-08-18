#include "relu.h"


    Relu::~Relu(){
        if(_input != nullptr) {
            delete _input;
            _input = nullptr;
        }
    }

    Relu::Relu (Relu &&layer){
        _input = layer._input;
        layer._input = nullptr;
    }

    Relu &Relu::operator=(Relu &&layer){
        if(this == &layer){
            return *this;
        }
        delete _input;
        _input = new Eigen::MatrixXd(*layer._input);
        layer._input = nullptr;
        return *this;
    }

    Eigen::MatrixXd Relu::forward(Eigen::MatrixXd &input){
        *_input = input;
        input = (input.array()<0).select(0,input);
        return input;
    }

    Eigen::MatrixXd Relu::backward(Eigen::MatrixXd &grad_input){
        grad_input = (_input->array()<0).select(0,grad_input);
        return grad_input;
    }

