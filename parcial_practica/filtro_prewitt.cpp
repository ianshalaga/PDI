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

Mat prewitt_v() {
	
	Mat kernel(3,3,CV_64F,Scalar(-1));
	
	for(int i=0;i<3;i++) { 
		kernel.at<double>(i,1) = 0;
		kernel.at<double>(i,2) = 1;
	}
	
	return kernel;
}

Mat prewitt_d() {
	
	Mat kernel(3,3,CV_64F,Scalar(-1));
	
	for(int i=0;i<3;i++) { 
		for(int j=0;j<3;j++) { 
			if (i == j)
				kernel.at<double>(i,j) = 0;
			if (i < j)
				kernel.at<double>(i,j) = 1;
		}
	}
	
	return kernel;
}

Mat prewitt_di() {
	
	Mat kernel(3,3,CV_64F,Scalar(-1));
	
	kernel.at<double>(0,2) = 0;
	kernel.at<double>(1,1) = 0;
	kernel.at<double>(2,0) = 0;
	
	kernel.at<double>(1,2) = 1;
	kernel.at<double>(2,1) = 1;
	kernel.at<double>(2,2) = 1;
	
	return kernel;
}

Mat filtro_prewitt(const Mat &imagen) {
	
	Mat kernel_ph = prewitt_h();
	Mat kernel_pv = prewitt_v();
	Mat kernel_pd = prewitt_d();
	Mat kernel_pdi = prewitt_di();
	
	Mat imagen_ph,imagen_pv,imagen_pd,imagen_pdi;
	threshold(convolve(imagen,kernel_ph),imagen_ph,0,255,THRESH_OTSU|THRESH_BINARY);
	threshold(convolve(imagen,kernel_pv),imagen_pv,0,255,THRESH_OTSU|THRESH_BINARY);
	threshold(convolve(imagen,kernel_pd),imagen_pd,0,255,THRESH_OTSU|THRESH_BINARY);
	threshold(convolve(imagen,kernel_pdi),imagen_pdi,0,255,THRESH_OTSU|THRESH_BINARY);
		
	vector<Mat> mascaras = {imagen_ph,imagen_pv,imagen_pd,imagen_pdi};
	Mat lineas = or_mascaras(mascaras);
	
	return lineas;	
}
