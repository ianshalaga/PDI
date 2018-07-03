#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "vector"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat promediar_imagenes(vector<Mat> imagenes) {
	
	int cantidad = imagenes.size();
	
	Mat promedio(imagenes[0].size(),CV_64F,Scalar(0));
	
	for(int k=0;k<imagenes.size();k++) {
		Mat imagen;
		imagenes[k].convertTo(imagen,CV_64F);
		promedio = promedio + imagen;
	}
	
	promedio = promedio/cantidad;
	
	promedio.convertTo(promedio,CV_8UC(1));
	
	return promedio;
}
