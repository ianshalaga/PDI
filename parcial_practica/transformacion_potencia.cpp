#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

// Ayuda a distinguir mejor los niveles de blancos

Mat transformacion_potencia(Mat lut_table,float c,float gamma) {
	
	int filas = lut_table.rows;
	
	for (int r=0;r<filas;r++) {
		lut_table.at<uchar>(r,0) = ajuste(c*pow(r,gamma));
	}
	
	return lut_table;
}
