#include "linear_layer.h"

Linear_Layer::Linear_Layer(int input_channels, int output_channels, double lr){

    _lr = lr;
    _weights->resize(input_channels,output_channels);
    *_weights =  Eigen::MatrixXd::Random(input_channels,output_channels);
    *_weights += Eigen::MatrixXd::Constant(input_channels,output_channels,1.);
    *_weights = (std::sqrt(2.0/(input_channels+output_channels))/2.0)*(*_weights); 
    _bias->resize(output_channels,1);
    _bias->setZero();

}
Eigen::MatrixXd Linear_Layer::forward(Eigen::MatrixXd &input){
    *_input = input;
    Eigen::MatrixXd output;
    output = (*_input)*(*_weights);
    for (int i = 0; i<output.cols(); i++){
        output.col(i) += _bias->coeff(i,0)*Eigen::MatrixXd::Constant(_input->rows(),1,1.0);
    }
    return output;
}

Eigen::MatrixXd Linear_Layer::backward(Eigen::MatrixXd &grad_output){

    *_grad_input = grad_output*(_weights->transpose());
    *_grad_bias = grad_output.colwise().sum();
    *_grad_weights = (_input->transpose())*grad_output;
    *_weights -= _lr*(*_grad_weights);
    *_bias -= _lr*(_grad_bias->transpose());
    return *_grad_input;
}

Linear_Layer::~Linear_Layer(){
    if(_weights != nullptr) {
        delete _weights;
        _weights = nullptr;
    }
    if(_bias != nullptr) {
        delete _bias;
        _bias = nullptr;
    }
    if(_input != nullptr) {
        delete _input;
        _input = nullptr;
    }
    if(_grad_input != nullptr){ 
        delete _grad_input;
        _grad_input  = nullptr;
    }
    if(_grad_bias != nullptr){
         delete _grad_bias;
         _grad_bias = nullptr;
    }
    if(_grad_weights != nullptr){ 
        delete _grad_weights;
        _grad_weights = nullptr;
    }
}

Linear_Layer::Linear_Layer (Linear_Layer &&layer){

    _weights = layer._weights;
    _bias = layer._bias;
    _input = layer._input;
    _grad_input = layer._grad_input;
    _grad_bias = layer._grad_bias;
    _grad_weights = layer._grad_weights;

    layer._weights = nullptr;
    layer._bias = nullptr;
    layer._input = nullptr;
    layer._grad_input = nullptr;
    layer._grad_bias = nullptr;
    layer._grad_weights = nullptr;
}

Linear_Layer &Linear_Layer::operator=(Linear_Layer &&layer){
    if(this == &layer){
        return *this;
    }
    delete _weights; 
    delete _bias;
    delete _input;
    delete _grad_input;
    delete _grad_bias;
    delete _grad_weights;

    _weights = new Eigen::MatrixXd(*layer._weights);
    _bias = new Eigen::MatrixXd(*layer._bias);
    _input = new Eigen::MatrixXd(*layer._input);
    _grad_input = new Eigen::MatrixXd(*layer._grad_input);
    _grad_bias = new Eigen::MatrixXd(*layer._grad_bias);
    _grad_weights = new Eigen::MatrixXd(*layer._grad_weights);

    layer._weights = nullptr;
    layer._bias = nullptr;
    layer._input = nullptr;
    layer._grad_input = nullptr;
    layer._grad_bias = nullptr;
    layer._grad_weights = nullptr;

    return *this;
}