#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat concatenar_v_color(vector<Mat> imagenes) {
	
	for(int k=1;k<imagenes.size();k++) {
		
		int filas = imagenes[k].rows;
		int columnas = imagenes[k].cols;
		
		if (imagenes[k].channels() == 1)
			cvtColor(imagenes[k],imagenes[k],CV_GRAY2BGR);
		
		resize(imagenes[k],imagenes[k],{imagenes[0].rows*columnas/filas,imagenes[0].rows},0,0,CV_INTER_LINEAR);
	}
	
	Mat concatenacion = imagenes[0];
	
	for(int k=1;k<imagenes.size();k++) { 
		concatenacion = mosaic(concatenacion,imagenes[k],true);
	}
	
	return concatenacion;
}
