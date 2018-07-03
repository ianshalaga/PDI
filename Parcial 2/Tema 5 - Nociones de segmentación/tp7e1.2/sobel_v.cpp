#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat sobel_v() {
	
	Mat kernel(3,3,CV_64F,Scalar(0));
	
	kernel.at<double>(0,0) = -1;
	kernel.at<double>(1,0) = -2;
	kernel.at<double>(2,0) = -1;
	
	kernel.at<double>(0,2) = 1;
	kernel.at<double>(1,2) = 2;
	kernel.at<double>(2,2) = 1;
	
	return kernel;
}
