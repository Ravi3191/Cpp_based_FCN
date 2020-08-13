#include "bce_loss.h"

Bce_Loss() : _loss{0}, _size{0} {}
void forward(Eigen::MatrixXd ground_truth, Eigen::MatrixXd predictions){
    _size = gronud_truth.rows();
    for(int i=0; i < gronud_truth.rows(); i++){
        if(ground_truth == 0){
            if(predictions(i,0) == 0.0){
                predictions(i,0) += 0.00001;
            }
            _loss += std::logf(predictions(i,1));
        }
        else{
            if(predictions(i,0) == 1.0){
                predictions(i,0) -= 0.00001;
            }
            _loss += std::logf(1-predictions(i,1));
        }
    }
    _loss = -_loss/_size;
}
Eigen::MatrixXd backward(){
    Eigen::MatrixXd grad;
    grad.reshape(_size,2);  

}