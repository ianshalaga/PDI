#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

using namespace std;
using namespace pdi;
using namespace cv;

vector<Mat> negativo_hsv(vector<Mat> hsv_vector) {

//	hsv_vector[0].convertTo(hsv_vector[0],CV_64F);
	hsv_vector[1].convertTo(hsv_vector[1],CV_64F);
	hsv_vector[2].convertTo(hsv_vector[2],CV_64F);
	
	int filas = hsv_vector[0].rows;
	int columnas = hsv_vector[0].cols;
	
	vector<Mat> neg_hsv(hsv_vector.size());
	
	for(int i=0;i<hsv_vector.size();i++) { 
		neg_hsv[i] = hsv_vector[i].clone();
	}
	
	for (int i=0;i<filas;i++) {
		for (int j=0;j<columnas;j++) {
			neg_hsv[0].at<uchar>(i,j) = (hsv_vector[0].at<uchar>(i,j) + 90) % 180;
			neg_hsv[2].at<double>(i,j) = 255 + (hsv_vector[2].at<double>(i,j)*(hsv_vector[1].at<double>(i,j) - 1));
			if (neg_hsv[2].at<double>(i,j) == 0)
				neg_hsv[1].at<double>(i,j) == 0;
			else
				neg_hsv[1].at<double>(i,j) = 255*(neg_hsv[2].at<double>(i,j) + hsv_vector[2].at<double>(i,j) - 255)/neg_hsv[2].at<double>(i,j);
		}
	}
	
	neg_hsv[1].convertTo(neg_hsv[1],CV_8UC(1));
	neg_hsv[2].convertTo(neg_hsv[2],CV_8UC(1));
	
	return neg_hsv;
}
