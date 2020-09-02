#include <vector>
#include <string>
#include <model.h>
#include <Eigen/Dense>
#include "read_csv.h"

int main() {

    int epochs;
    double lr;

    Read_data training_data("Breast_Cancer_Data/x_train.csv",319,10);
    training_data.normalize();

    Read_data training_labels("Breast_Cancer_Data/y_train.csv",319,1);

    Read_data test_data("Breast_Cancer_Data/x_test.csv",319,10);
    test_data.normalize(training_data.get_mean(),training_data.get_variance());

    Read_data test_labels("Breast_Cancer_Data/y_test.csv",319,1);


    while(true){
        std::cout << "Enter number of epochs: ";
        std::cin >> epochs;
        std::cout << std::endl;
        if(epochs < 0){
            std::cout << "Number of epochs should be a positive integer" << std::endl;
        }
        else{
            break;
        }
    }

    while(true){
        std::cout << "Enter learning_rate: ";
        std::cin >> lr;
        std::cout << std::endl;
        if(lr < 0){
            std::cout << "learning rate should be a positive number" << std::endl;
        }
        else{
            break;
        }
    }

    Model model(lr);

    std::cout << "starting training" << std::endl;

    model.train(epochs,training_data.get_data(),training_labels.get_data());

    std::cout << " The test accuracy is: " << model.get_accuracy(test_data.get_data(),test_labels.get_data()) << std::endl;

    return 0;
}