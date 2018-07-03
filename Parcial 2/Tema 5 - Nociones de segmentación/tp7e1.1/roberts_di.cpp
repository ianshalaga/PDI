#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat roberts_di() {
	
	Mat roberts2(2,2,CV_8SC(1),Scalar(0));
	
	roberts2.at<uchar>(0,1) = -1;
	roberts2.at<uchar>(1,0) = 1;

	return roberts2;
}
