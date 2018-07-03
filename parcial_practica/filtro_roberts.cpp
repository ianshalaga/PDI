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

Mat roberts_di() {
	
	Mat roberts2(2,2,CV_8SC(1),Scalar(0));
	
	roberts2.at<uchar>(0,1) = -1;
	roberts2.at<uchar>(1,0) = 1;
	
	return roberts2;
}

Mat filtro_roberts(const Mat &imagen) {
	
	Mat kernel_rd = roberts_d();
	Mat kernel_rdi = roberts_di();
	
	Mat imagen_rd,imagen_rdi;
	threshold(convolve(imagen,kernel_rd),imagen_rd,0,255,THRESH_OTSU|THRESH_BINARY);
	threshold(convolve(imagen,kernel_rdi),imagen_rdi,0,255,THRESH_OTSU|THRESH_BINARY);
	
	vector<Mat> mascaras = {imagen_rd,imagen_rdi};
	Mat lineas = or_mascaras(mascaras);
	
	return lineas;
}
