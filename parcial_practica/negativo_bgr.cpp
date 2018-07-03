#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

using namespace std;
using namespace pdi;
using namespace cv;

vector<Mat> negativo_bgr(vector<Mat> bgr_vector) {
	
	int filas = bgr_vector[0].rows;
	int columnas = bgr_vector[0].cols;
	
	for (int i=0;i<filas;i++) {
		for (int j=0;j<columnas;j++) {
//			bgr_vector[0].at<uchar>(i,j) = (bgr_vector[1].at<uchar>(i,j) + bgr_vector[2].at<uchar>(i,j) + 255) % 255;
			bgr_vector[0].at<uchar>(i,j) = 255 - bgr_vector[0].at<uchar>(i,j);
//			bgr_vector[1].at<uchar>(i,j) = (bgr_vector[0].at<uchar>(i,j) + bgr_vector[2].at<uchar>(i,j) + 255) % 255;
			bgr_vector[1].at<uchar>(i,j) = 255 - bgr_vector[1].at<uchar>(i,j);
//			bgr_vector[2].at<uchar>(i,j) = (bgr_vector[0].at<uchar>(i,j) + bgr_vector[1].at<uchar>(i,j) + 255) % 255;
			bgr_vector[2].at<uchar>(i,j) = 255 - bgr_vector[2].at<uchar>(i,j);
		}
	}
	return bgr_vector;
}
