#ifndef BCE_LOSS
#define BCE_LOSS

#include <iostream>
#include <Eigen/Core>
#include <math.h>

class Bce_Loss{
    public:
        Bce_Loss(); // constructor
        void forward(const Eigen::MatrixXd &ground_truth, Eigen::MatrixXd &predictions); // forward function to calculate loss.
        Eigen::MatrixXd backward(); // propagates loss backwards.
        double get_loss();
        ~Bce_Loss(){}
        Bce_Loss (const Bce_Loss&) = delete;
        Bce_Loss& operator= (const Bce_Loss&) = delete;
    private:
        double _loss;
        int _size;
        Eigen::MatrixXd _loss_vector,_gt;
};

#endif
