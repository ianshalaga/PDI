#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat laplaciano_n4() {
	
	Mat kernel(3,3,CV_64F,Scalar(0));
	
	kernel.at<double>(0,1) = -1;
	kernel.at<double>(1,0) = -1;
	kernel.at<double>(1,2) = -1;
	kernel.at<double>(2,1) = -1;
	kernel.at<double>(1,1) = 4;
	
	return kernel;
}

Mat filtro_laplaciano4(const Mat &imagen) {
	
	Mat kernel_ln4 = laplaciano_n4();
	
	Mat imagen_ln4;
	threshold(convolve(imagen,kernel_ln4),imagen_ln4,0,255,THRESH_OTSU|THRESH_BINARY);
	
	return imagen_ln4;
}
