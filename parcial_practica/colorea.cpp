#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

vector<Mat> colorea(vector<Mat> hsv_vector,Mat mascara,int H,int S,int V) {
	
	int filas = mascara.rows;
	int columnas = mascara.cols;
	
	for (int i=0;i<filas;i++) {
		for (int j=0;j<columnas;j++) {
			if (mascara.at<uchar>(i,j) == 255) {
				hsv_vector[0].at<uchar>(i,j) = H;
				hsv_vector[1].at<uchar>(i,j) = S;
				hsv_vector[2].at<uchar>(i,j) = V;
			}
		}
	}
	
	return hsv_vector;
}
