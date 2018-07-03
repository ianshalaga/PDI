#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat filtro_pa_sc_ld(const int &filas,const int &columnas) {
	
	Mat kernel(filas,columnas,CV_64F,Scalar(-1));
	
	for(int i=0;i<filas;i++) {
		for(int j=0;j<columnas;j++) {
			if (i == j)
				kernel.at<double>(i,j) = 2;
		}
	}
	
	return kernel;
}
