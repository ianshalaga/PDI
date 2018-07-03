#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

using namespace std;
using namespace pdi;
using namespace cv;

Mat rotar(const Mat &imagen,const vector<Vec2f> &rho_tita) {
	
	Mat rotada = imagen.clone();
	
	if (rho_tita[0][1] != 0)
		if (rho_tita[0][1] > CV_PI/2)
			rotada = rotate(imagen,(rho_tita[0][1]-CV_PI/2)*180/CV_PI);
		else
			rotada = rotate(imagen,(rho_tita[0][1]+CV_PI)*180/CV_PI);
	
	return rotada;
}
