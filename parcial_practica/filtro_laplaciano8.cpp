#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat laplaciano_n8(const int &filas,const int &columnas) {
	
	Mat kernel = filtro_pa(filas,columnas,0);
	
	return kernel;
}

Mat filtro_laplaciano8(const Mat &imagen,const int &filas,const int &columnas) {
	
	Mat kernel_ln8 = laplaciano_n8(filas,columnas);
	
	Mat imagen_ln8;
	threshold(convolve(imagen,kernel_ln8),imagen_ln8,0,255,THRESH_OTSU|THRESH_BINARY);
	
	return imagen_ln8;
}
