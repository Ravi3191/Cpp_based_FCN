#include "read_csv.h"


void Read_data::fill_col(){
    std::string line,name;
    std::ifstream file(_file_name);
    if(file.is_open()){
        std::getline(filestream, line);
        std::replace(line.begin(), line.end(), ',', ' ');
        std::istringstream linestream(line);
        while(line>>name){
            _col_names.push_back(name);
        }
    }
    file.close();
}

void Read_data::fill_matrix(){
    int col{0},iters{0};
    //Eigen::Matrix<double,_n_rows,_n_cols> Matrix;
    _data.setZero();
    std::vector<double> _mean(_n_cols,0);
    std::vector<double> _variance(_n_cols,0);
    std::ifstream file(_file_name);
    double num;
    if(file.is_open()){
        while(std::getline(file, line)){
            std::replace(line.begin(), line.end(), ',', ' ');
            std::istringstream linestream(line);
            if(iters > 0){
                linestream >> num;
                col = 0;
                while(linestream>>num){
                    _data(iters-1,col) = num;
                    _mean[col] += num;
                    variance[col] += num*num;
                    col++;
                }
                std::cout << std::endl;
            }
            iters++; 
    }
    }
    file.close();
    
    for(int i = 0; i <_n_cols; i++){
        _mean[i]=_mean[i]/_n_rows;
    }
    for(int i = 0; i<_n_cols; i++){
        _variance[i] = _variance[i]/_n_rows - _mean[i]*_mean[i];
    }
    for(int i = 0; i<_n_cols; i++){
        _data.col(i) -= _mean[i];
        _data.col(i) /= _variance[i];
    }
    std::cout << " Data has been read and processed for the " << _file_name << ". " << std::endl;
}

Read_data::Read_data(const std::string name, const int rows, const int cols) : _file_name{name}, _n_rows{rows}, _n_cols{cols}{
    
    Read_data::fill_col;
    Read_data::fill_matrix;
}

Eigen::Matrix<double,n_rows,n_cols> Read_data::get_data(){
    return _data;
}

std::vector<std::string> Read_data::get_names(){
    return _col_names;
}