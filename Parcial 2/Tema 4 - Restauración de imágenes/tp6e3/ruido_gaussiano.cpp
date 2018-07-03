#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat ruido_gaussiano(const Mat &imagen,const float &media,const float &stdev) {
	
	Mat normalizada = imagen.clone();
	normalize(imagen,normalizada,0,1,CV_MINMAX,CV_64F);
	
	Mat ruido(imagen.size(),CV_64F);
	
	randn(ruido,media,stdev);
	
	Mat imagen_ruido = normalizada + ruido;
	
	normalize(imagen_ruido,imagen_ruido,0,255,CV_MINMAX,CV_8UC(1));
	
	return imagen_ruido;
}
