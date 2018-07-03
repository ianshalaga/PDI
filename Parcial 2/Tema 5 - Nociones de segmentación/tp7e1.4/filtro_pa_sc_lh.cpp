#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat filtro_pa_sc_lh(const int &filas,const int &columnas) {
	
	Mat kernel(filas,columnas,CV_64F,Scalar(-1));
	
	for(int i=0;i<columnas;i++) { 
		kernel.at<double>(filas/2,i) = 2;
	}
	
	return kernel;
}
