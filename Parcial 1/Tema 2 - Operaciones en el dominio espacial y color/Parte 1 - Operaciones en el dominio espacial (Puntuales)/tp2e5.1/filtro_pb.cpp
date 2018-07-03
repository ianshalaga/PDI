#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat filtro_pb(int filas,int columnas) {
	Mat kernel(filas,columnas,CV_64F,Scalar(1));
	kernel = (1./(filas*columnas))*kernel;
	return kernel;
}
