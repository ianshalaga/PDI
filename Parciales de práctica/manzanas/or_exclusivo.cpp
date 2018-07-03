#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

using namespace std;
using namespace pdi;
using namespace cv;

// Las imagenes deben ser del mismo tamaño

Mat or_exclusivo(const Mat &imagen1,const Mat &imagen2) {
	
	int filas = imagen1.rows;
	int columnas = imagen2.cols;
	
	Mat resultado(filas,columnas,CV_8UC(1));
	
	for(int i=0;i<filas;i++) { 
		for(int j=0;j<columnas;j++) { 
			if (imagen1.at<uchar>(i,j) != imagen2.at<uchar>(i,j))
				resultado.at<uchar>(i,j) = 255;
			else
				resultado.at<uchar>(i,j) = 0;
		}
	}
	
	return resultado;
}
