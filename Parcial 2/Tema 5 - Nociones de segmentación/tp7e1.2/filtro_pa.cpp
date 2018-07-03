#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat filtro_pa(const int &filas,const int &columnas,const int &suma) {
	
	Mat kernel(filas,columnas,CV_64F,Scalar(-1));
	
	if (suma == 1)
		kernel.at<double>(filas/2,columnas/2) = filas*columnas;
	if (suma == 0)
		kernel.at<double>(filas/2,columnas/2) = (filas*columnas)-1;
	
	return kernel;
}
