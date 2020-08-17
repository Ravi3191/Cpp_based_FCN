#ifndef BCE_LOSS
#define BCE_LOSS

#include <iostream>
#include <Eigen/Core>
#include <math.h>

class Bce_Loss{
    public:
        Bce_Loss();
        void forward(Eigen::MatrixXd ground_truth, Eigen::MatrixXd predictions);
        Eigen::MatrixXd backward();
    private:
        double _loss;
        int _size;
        Eigen::MatrixXd _loss_vector,_gt;
};

#endif
