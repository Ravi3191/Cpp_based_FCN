#ifndef READ_CSV
#define READ_CSV

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <Eigen/Core>

class Read_data{
public:
    Read_data(const std::string name, const int rows, const int cols); //constructor
    std::vector<std::string> get_names(); 
    void fill_matrix(); // reads data from the csv file and fills the _data matrix
    void fill_col(); // fills the _col_names vector
    void normalize(std::vector<double> mean,std::vector<double> variance); // normalizes _data by using the provided mean and variance
    void normalize(); //normalizes _data by using _mean and _variance of the same dataset
    Eigen::MatrixXd get_data();
    std::vector<double> get_mean(){return _mean;}
    std::vector<double> get_variance(){return _variance;}


private:
    std::string _file_name;
    std::vector<std::string> _col_names;
    std::vector<double> _mean;
    std::vector<double> _variance;
    const int _n_rows;
    const int _n_cols;
    Eigen::MatrixXd _data;
};

#endif
