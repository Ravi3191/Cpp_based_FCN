#ifndef FCN_OPERATIONS
#define FCN_OPERATIONS
#include <Eigen/Core>

class fcn_operations{
public:
virtual Eigen::MatrixXd forward(Eigen::MatrixXd &input) = 0;
virtual  Eigen::MatrixXd backward(Eigen::MatrixXd &grad_output) = 0;
virtual Eigen::MatrixXd getPredictions() {return Eigen::MatrixXd(1,1)};
//virtual ~fcn_operations()=0;
private:
const float _lr{0.01};
};

#endif