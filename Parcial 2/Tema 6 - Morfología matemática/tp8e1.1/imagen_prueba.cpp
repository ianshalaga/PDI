#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat imagen_prueba() {
	
	Mat ip(12,12,CV_8UC(1),Scalar(0));
	
	ip.at<uchar>(1,1) = 255;
	ip.at<uchar>(1,2) = 255;
	ip.at<uchar>(1,3) = 255;
	
	ip.at<uchar>(2,3) = 255;
	ip.at<uchar>(2,9) = 255;
	
	ip.at<uchar>(3,3) = 255;
	ip.at<uchar>(3,8) = 255;
	ip.at<uchar>(3,9) = 255;
	ip.at<uchar>(3,10) = 255;
	
	ip.at<uchar>(4,2) = 255;
	ip.at<uchar>(4,3) = 255;
	ip.at<uchar>(4,4) = 255;
	ip.at<uchar>(4,8) = 255;
	ip.at<uchar>(4,9) = 255;
	ip.at<uchar>(4,10) = 255;
	
	ip.at<uchar>(6,1) = 255;
	
	ip.at<uchar>(7,2) = 255;
	ip.at<uchar>(7,8) = 255;
	ip.at<uchar>(7,9) = 255;
	ip.at<uchar>(7,10) = 255;
	
	ip.at<uchar>(8,3) = 255;
	ip.at<uchar>(8,10) = 255;
	
	ip.at<uchar>(9,7) = 255;
	ip.at<uchar>(9,8) = 255;
	ip.at<uchar>(9,9) = 255;
	ip.at<uchar>(9,10) = 255;
	
	ip.at<uchar>(10,1) = 255;
	ip.at<uchar>(10,8) = 255;
	ip.at<uchar>(10,9) = 255;
	ip.at<uchar>(10,10) = 255;

	return ip;
}
