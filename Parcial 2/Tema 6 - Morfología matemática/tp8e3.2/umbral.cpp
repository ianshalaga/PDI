#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

using namespace std;
using namespace pdi;
using namespace cv;

Mat umbral(const Mat &imagen,const int &nivel_transicion) {
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	Mat umbral(filas,columnas,CV_8UC(1));
	
	for(int i=0;i<filas;i++) {
		for(int j=0;j<columnas;j++) {
			if (imagen.at<uchar>(i,j) <= nivel_transicion)
				umbral.at<uchar>(i,j) = 0;
			else
				umbral.at<uchar>(i,j) = 255;
		}
	}
	
	return umbral;
}
