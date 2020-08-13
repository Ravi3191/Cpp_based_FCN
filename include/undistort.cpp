#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

int main(){
Mat img = cv::imread("/home/ravi/jackal_images/frame0030.jpg");
int h = img.rows;
int w = img.cols;
std::cout << " h,w " << h << " " << w << std::endl;
cv::imshow("Display window", img);
int k = cv::waitKey(0); // Wait for a keystroke in the window
if(k == 's')
{
    cv::imwrite("starry_night.png", img);
}
return 0;
}