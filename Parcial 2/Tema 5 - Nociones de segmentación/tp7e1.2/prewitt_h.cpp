#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat prewitt_h() {
	
	Mat kernel(3,3,CV_64F,Scalar(-1));
	
	for(int j=0;j<3;j++) { 
		kernel.at<double>(1,j) = 0;
		kernel.at<double>(2,j) = 1;
	}
	
	return kernel;
}
