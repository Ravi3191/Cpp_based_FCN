#include "read_csv.h"


void Read_data::fill_col(){
    std::string line,name;
    std::ifstream file(_file_name);
    if(file.is_open()){
        std::getline(file, line);
        std::replace(line.begin(), line.end(), ',', ' ');
        std::istringstream linestream(line);
        while(linestream >> name){
            _col_names.push_back(name);
        }
    }
    file.close();
}

void Read_data::fill_matrix(){
    int col{0},iters{0};
    std::string line;
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
                    _variance[col] += num*num;
                    col++;
                }
                //std::cout << std::endl;
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

    std::cout << " Data has been read and processed for the " << _file_name << ". " << std::endl;
}

void Read_data::normalize(std::vector<double> mean,std::vector<double> variance){
    for(int i = 0; i<_n_cols; i++){
        Eigen::MatrixXd ones(_n_rows,1);
        ones.fill(1.0);
        _data.col(i) -=  ones*mean[i];
        _data.col(i) /= variance[i];
    }
}

void Read_data::normalize(){
    for(int i = 0; i<_n_cols; i++){
        Eigen::MatrixXd ones(_n_rows,1);
        ones.fill(1.0);
        _data.col(i) -=  ones*_mean[i];
        _data.col(i) /= _variance[i];
    }
}

Read_data::Read_data(const std::string name, const int rows, const int cols) : _file_name{name}, _n_rows{rows}, _n_cols{cols}, _mean(cols,0),_variance(cols,0){
    _data.resize(_n_rows,_n_cols);
    Read_data::fill_col();
    Read_data::fill_matrix();
}

Eigen::MatrixXd Read_data::get_data(){
    return _data;
}

std::vector<std::string> Read_data::get_names(){
    return _col_names;
}