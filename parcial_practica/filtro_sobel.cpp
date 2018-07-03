#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat sobel_h() {
	
	Mat kernel(3,3,CV_64F,Scalar(0));
	
	kernel.at<double>(0,0) = -1;
	kernel.at<double>(0,1) = -2;
	kernel.at<double>(0,2) = -1;
	
	kernel.at<double>(2,0) = 1;
	kernel.at<double>(2,1) = 2;
	kernel.at<double>(2,2) = 1;
	
	return kernel;
}

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

Mat sobel_d() {
	
	Mat kernel(3,3,CV_64F,Scalar(0));
	
	kernel.at<double>(0,1) = 1;
	kernel.at<double>(0,2) = 2;
	kernel.at<double>(1,2) = 1;
	
	kernel.at<double>(1,0) = -1;
	kernel.at<double>(2,0) = -2;
	kernel.at<double>(2,1) = -1;
	
	return kernel;
}

Mat sobel_di() {
	
	Mat kernel(3,3,CV_64F,Scalar(0));
	
	kernel.at<double>(0,0) = -2;
	kernel.at<double>(0,1) = -1;
	kernel.at<double>(1,0) = -1;
	
	kernel.at<double>(1,2) = 1;
	kernel.at<double>(2,1) = 1;
	kernel.at<double>(2,2) = 2;
	
	return kernel;
}

Mat filtro_sobel(const Mat &imagen) {
	
	Mat kernel_sh = sobel_h();
	Mat kernel_sv = sobel_v();
	Mat kernel_sd = sobel_d();
	Mat kernel_sdi = sobel_di();
	
	Mat imagen_sh,imagen_sv,imagen_sd,imagen_sdi;
	threshold(convolve(imagen,kernel_sh),imagen_sh,0,255,THRESH_OTSU|THRESH_BINARY);
	threshold(convolve(imagen,kernel_sv),imagen_sv,0,255,THRESH_OTSU|THRESH_BINARY);
	threshold(convolve(imagen,kernel_sd),imagen_sd,0,255,THRESH_OTSU|THRESH_BINARY);
	threshold(convolve(imagen,kernel_sdi),imagen_sdi,0,255,THRESH_OTSU|THRESH_BINARY);
	
	vector<Mat> mascaras = {imagen_sh,imagen_sv,imagen_sd,imagen_sdi};
	Mat lineas = or_mascaras(mascaras);
	
	return lineas;	
}
