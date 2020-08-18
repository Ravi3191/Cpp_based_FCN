#ifndef MODEL
#define MODEL

#include <iostream>
#include <vector>
#include <memory>
#include "bce_loss.h"
#include "linear_layer.h"
#include "relu.h"
#include "sigmoid.h"
#include "fcn_operations.h"
#include <Eigen/Core>

class Model{
public:
    Model();
    //~Model(){}
    void forward();
    void backward();
    double calculate_loss();
    Eigen::MatrixXd get_predictions(Eigen::MatrixXd data);
    double train(int epochs, Eigen::MatrixXd &input, Eigen::MatrixXd &gt);
    
private:
    std::vector<std::unique_ptr<fcn_operations>> _model;
    Bce_Loss _criterion;
    Eigen::MatrixXd _data, _ground_truth, _predictions;
    double _loss;

};

#endif