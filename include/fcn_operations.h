#ifndef FCN_OPERATIONS
#define FCN_OPERATIONS
#include <Eigen/Core>

class fcn_operations{
public:
virtual Eigen::MatrixXd forward(Eigen::MatrixXd &input) = 0; // forward function used in prediction.
virtual  Eigen::MatrixXd backward(Eigen::MatrixXd &grad_output) = 0; // backward function used for performing gradient descent and updating weights
virtual Eigen::MatrixXd getPredictions() {return Eigen::MatrixXd(1,1);} // returns predictions from the network.
virtual ~fcn_operations(){}

};
#endif