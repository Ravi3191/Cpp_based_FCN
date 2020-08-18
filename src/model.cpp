#include "model.h"

    Model::Model(){
        _model.emplace_back(std::make_unique<Linear_Layer>(10,20));
        _model.emplace_back(std::make_unique<Relu>());
        _model.emplace_back(std::make_unique<Linear_Layer>(20,80));
        _model.emplace_back(std::make_unique<Relu>());
        _model.emplace_back(std::make_unique<Linear_Layer>(80,10));
        _model.emplace_back(std::make_unique<Relu>());
        _model.emplace_back(std::make_unique<Linear_Layer>(10,1));
        _model.emplace_back(std::make_unique<Sigmoid>());
    }

    void Model::forward(){
        Eigen::MatrixXd input_mat = _data;
        for (int i = 0; i<_model.size(); i++){
            input_mat = _model[i]->forward(input_mat);
        }
        _predictions = _model[_model.size()-1]->getPredictions();
        _criterion.forward(_ground_truth,_predictions);
    }

    void Model::backward(){
        Eigen::MatrixXd grad = _criterion.backward();
        for (int i = _model.size()-1; i >=0; i--){
            grad = _model[i]->backward(grad);
        }
    }

    double Model::calculate_loss(){
        return _criterion.get_loss();
    }

    Eigen::MatrixXd Model::get_predictions(Eigen::MatrixXd data){
        return _predictions;
    }

    double Model::train(int epochs, Eigen::MatrixXd &input, Eigen::MatrixXd &gt){
        _data = input;
        _ground_truth = gt;
        for(int i=0; i<epochs; i++){
            forward();
            backward();
            std::cout << "EPOCH:  " << i << "Training Loss: " << _criterion.get_loss() << std::endl;
        }
        return _criterion.get_loss();
    }