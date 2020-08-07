#ifndef READ_CSV
#define READ_CSV

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <Eigen/Dense>

class Read_data{
public:
    Read_data(const std::string name, const int rows, const int cols);
    std::vector<std::string> get_names();
    void fill_matrix();
    void fill_col();
    Eigen::Matrix<double,_n_rows,_n_cols> get_data();


private:
    std::string _file_name;
    std::vector<std::string> _col_names;
    std::vector<double> _mean;
    std::vector<double> _variance;
    const int _n_rows;
    const int _n_cols;
    Eigen::Matrix<double,n_rows,n_cols> _data;
};

#endif