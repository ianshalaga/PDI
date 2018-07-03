#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

using namespace std;
using namespace pdi;
using namespace cv;

float detectar_angulo(const Mat &imagen,const vector<Vec2f> &rho_tita) {
	
	float angulo;
	
	if (rho_tita[0][1] > CV_PI/2)
		angulo = (rho_tita[0][1])*180/CV_PI;
	else
		angulo = (CV_PI - rho_tita[0][1])*180/CV_PI;
	
	return angulo;
}
