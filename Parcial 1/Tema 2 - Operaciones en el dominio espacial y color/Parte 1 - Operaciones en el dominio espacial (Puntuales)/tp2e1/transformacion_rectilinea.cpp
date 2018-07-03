#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

//	r: valor de entrada
//	a: factor de ganancia (pendiente)
//	c: offset (ordenada al origen)
	
Mat transformacion_rectilinea(Mat lut_table,float a,float c) {
	int filas = lut_table.rows;
	for (int r=0;r<filas;r++) {
		lut_table.at<uchar>(r,0) = ajuste(a*r+c);
	}
	return lut_table;
}
