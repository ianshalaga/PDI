#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat lap_of_gauss() {
	
	Mat kernel(5,5,CV_64F,Scalar(0));
	
	kernel.at<double>(0,2) = -1;
	
	kernel.at<double>(1,1) = -1;
	kernel.at<double>(1,2) = -2;
	kernel.at<double>(1,3) = -1;
	
	kernel.at<double>(2,0) = -1;
	kernel.at<double>(2,1) = -2;
	kernel.at<double>(2,2) = 16;
	kernel.at<double>(2,3) = -2;
	kernel.at<double>(2,4) = -1;
	
	kernel.at<double>(3,1) = -1;
	kernel.at<double>(3,2) = -2;
	kernel.at<double>(3,3) = -1;
	
	kernel.at<double>(4,2) = -1;
	
	return kernel;
}
