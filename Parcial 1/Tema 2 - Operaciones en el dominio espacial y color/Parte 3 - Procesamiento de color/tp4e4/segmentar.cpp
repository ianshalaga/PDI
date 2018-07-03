#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

vector<Mat> segmentar(vector<Mat> bgr_hsv,vector<Mat> mascara) {
	int filas = mascara[0].rows;
	int columnas = mascara[0].cols;
	for (int i=0;i<filas;i++) {
		for (int j=0;j<columnas;j++) {
			if (mascara[0].at<uchar>(i,j) == 0 || mascara[1].at<uchar>(i,j) == 0 || mascara[2].at<uchar>(i,j) == 0) {
				bgr_hsv[0].at<uchar>(i,j) = 0;
				bgr_hsv[1].at<uchar>(i,j) = 0;
				bgr_hsv[2].at<uchar>(i,j) = 0;
			}
		}
	}
	return bgr_hsv;
}
