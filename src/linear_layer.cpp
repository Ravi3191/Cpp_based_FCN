#include "linear_layer.h"

Linear_Layer(int input_channels, int output_channels){
    _weights.reshape(input_channels,output_channels);
    _weights.Random();
    _weights += MatrixXd::Constant(input_channels,output_channels,1.);
    _weights *= std::sqrt(2/(input_channels+output_channels))/2; 
    _bias.reshape(output_channels,1);
    _bias.setZero();

}
void forward(EIgen::MatrixXd input){
    _input = input;
    Eigen::MatrixXd output;
    output = _input*_weights;

}
void backward(Eigen::MatrixXd grad_output){
    grad_input = grad_output*weights.transpose();
    grad_bias = grad_output.rowwise().sum();
    grad_weights = _input.transpose()*grad_output;
}