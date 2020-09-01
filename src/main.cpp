#include <vector>
#include <string>
#include <model.h>
#include <Eigen/Dense>
#include "read_csv.h"

int main() {
    Model model;
    int epochs;
    Read_data training_data("x_train.csv",319,10);
    training_data.normalize();
    std::cout << "Successfully read training data: " << std::endl;
    Read_data training_labels("y_train.csv",319,1);
    std::cout << "Successfully read training labels: " << std::endl;
    Eigen::MatrixXd data;
    Eigen::MatrixXd gt;
    data = training_data.get_data();
    gt = training_labels.get_data();
    std::cout << "starting training" << std::endl;
    std::cout << "Enter number of epochs: ";
    std::cin >> epochs;
    std::cout << std::endl;
    model.train(epochs,data,gt);
    return 0;
}