#include "model.h"

    Model::Model(){

        _model.emplace_back(std::make_unique<Linear_Layer>(10,20));
        _model.emplace_back(std::make_unique<Relu>());
        
       _model.emplace_back(std::make_unique<Linear_Layer>(20,40));
        _model.emplace_back(std::make_unique<Relu>());
        

        _model.emplace_back(std::make_unique<Linear_Layer>(40,10));
        _model.emplace_back(std::make_unique<Relu>());

        _model.emplace_back(std::make_unique<Linear_Layer>(10,1));
        _model.emplace_back(std::make_unique<Sigmoid>());
    }

    void Model::forward(){
        Eigen::MatrixXd input_mat = _data;
        for (int i = 0; i<_model.size(); i++){
            input_mat = _model[i]->forward(input_mat);
        }
        _criterion.forward(_ground_truth,input_mat);
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

    Eigen::MatrixXd Model::get_predictions(Eigen::MatrixXd &data){
        Eigen::MatrixXd test_mat = data;
        for (int i = 0; i<_model.size(); i++){
            test_mat = _model[i]->forward(test_mat);
        }
        Eigen::MatrixXd predictions = _model[_model.size()-1]->getPredictions();
        return predictions;
    }

    Eigen::MatrixXd Model::get_predictions(){

        Eigen::MatrixXd predictions = _model[_model.size()-1]->getPredictions();
        return predictions;
    }

    double Model::get_accuracy(Eigen::MatrixXd &data,Eigen::MatrixXd &labels){
        double acc{0};
        int data_points = labels.rows();
        Eigen::MatrixXd preds = get_predictions(data);
        for(int i=0; i<data_points; i++){
            if(labels(i,0)==preds(i,0)) acc += 1;
        }
        return acc/data_points;
    }

    double Model::get_accuracy(){
        double acc{0};
        int data_points = _ground_truth.rows();
        Eigen::MatrixXd preds = get_predictions();
        for(int i=0; i<data_points; i++){
            if(_ground_truth(i,0)==preds(i,0)) acc += 1;
        }
        return acc/data_points;
    }

    double Model::train(int epochs,const Eigen::MatrixXd &input,const Eigen::MatrixXd &gt){
        _data = input;
        _ground_truth = gt;
        for(int i=0; i<epochs; i++){
            forward();
            backward();
            std::cout << "EPOCH:  " << i << ", Training Loss: " << _criterion.get_loss() << ", accuracy: " << Model::get_accuracy() << std::endl;
        }
        return _criterion.get_loss();
    }