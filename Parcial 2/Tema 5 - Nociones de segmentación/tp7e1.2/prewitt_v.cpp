#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat prewitt_v() {
	
	Mat kernel(3,3,CV_64F,Scalar(-1));
	
	for(int i=0;i<3;i++) { 
		kernel.at<double>(i,1) = 0;
		kernel.at<double>(i,2) = 1;
	}
	
	return kernel;
}
