#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat concatenar_h_gray(vector<Mat> imagenes) {
	
	for(int k=1;k<imagenes.size();k++) {
		
		int filas = imagenes[k].rows;
		int columnas = imagenes[k].cols;
		
		resize(imagenes[k],imagenes[k],{imagenes[0].rows*columnas/filas,imagenes[0].rows},0,0,CV_INTER_LINEAR);
		
		if (imagenes[k].channels() == 3)
			cvtColor(imagenes[k],imagenes[k],CV_BGR2GRAY);
	}
	
	Mat concatenacion = imagenes[0];
	
	for(int k=1;k<imagenes.size();k++) { 
		concatenacion = mosaic(concatenacion,imagenes[k],false);
	}
	
	return concatenacion;
}
