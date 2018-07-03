#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

float determinar_valor(int area) {
	
	float valor;
	
	if (area < 3500)
		valor = 0.01;
	else if (area < 4200)
		valor = 0.02;
	else if (area < 4500)
		valor = 0.1;
	else if (area < 5400)
		valor = 0.05;
	else if (area < 6000)
		valor = 0.2;
	else if (area < 6400)
		valor = 1;
	else if (area < 7000)
		valor = 0.5;
	else 
		valor = 2;
	
	return valor;
}
