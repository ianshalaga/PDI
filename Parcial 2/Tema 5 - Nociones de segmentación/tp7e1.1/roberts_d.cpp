#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat roberts_d() {
	
	Mat roberts1(2,2,CV_8SC(1),Scalar(0));
	
	roberts1.at<uchar>(0,0) = -1;
	roberts1.at<uchar>(1,1) = 1;	

	return roberts1;
}
