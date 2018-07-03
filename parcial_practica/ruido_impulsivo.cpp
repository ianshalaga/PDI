#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

using namespace std;
using namespace pdi;
using namespace cv;

Mat ruido_impulsivo(const Mat &imagen,const int &bajo,const int &alto) {
	
	Mat ruido(imagen.size(),CV_8UC(1),Scalar(0));
	randu(ruido,bajo,alto);
	
	Mat negro = ruido < 10;
	Mat blanco = ruido > 245;
	
	Mat imagen_ruido = imagen.clone();
	
	imagen_ruido.setTo(alto,blanco);
	imagen_ruido.setTo(bajo,negro);
	
	return imagen_ruido;
}
