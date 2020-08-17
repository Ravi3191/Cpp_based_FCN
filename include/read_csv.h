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
    Read_data(const std::string name, const int rows, const int cols);
    std::vector<std::string> get_names();
    void fill_matrix();
    void fill_col();
    void normalize(std::vector<double> mean,std::vector<double> variance);
    void normalize();
    Eigen::MatrixXd get_data();


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
