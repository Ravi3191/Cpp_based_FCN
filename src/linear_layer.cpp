#include "linear_layer.h"

Linear_Layer::Linear_Layer(int input_channels, int output_channels){
    _weights.resize(input_channels,output_channels);
    _weights.Random();
    _weights += Eigen::MatrixXd::Constant(input_channels,output_channels,1.);
    _weights *= std::sqrt(2/(input_channels+output_channels))/2; 
    _bias.resize(output_channels,1);
    _bias.setZero();

}
Eigen::MatrixXd Linear_Layer::forward(Eigen::MatrixXd input){
    _input = input;
    Eigen::MatrixXd output;
    output = _input*_weights;
    for (int i = 0; i<output.cols(); i++){
        Eigen::MatrixXd ones(_input.rows(),1);
        output.col(i) += _bias(i,0)*ones;
    }
    return output;

}
void Linear_Layer::backward(Eigen::MatrixXd grad_output){
    _grad_input = grad_output*_weights.transpose();
    _grad_bias = grad_output.colwise().sum();
    _grad_weights = _input.transpose()*grad_output;
}