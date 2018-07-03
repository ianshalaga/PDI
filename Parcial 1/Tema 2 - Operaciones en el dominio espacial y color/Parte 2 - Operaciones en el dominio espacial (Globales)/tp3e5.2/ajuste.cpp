#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

using namespace std;
using namespace pdi;
using namespace cv;

// Ajusta el rango de valores entre 0 y 255

int ajuste(int intensidad) {
	
	if (intensidad < 0)
		intensidad = 0;
	
	if (intensidad > 255)
		intensidad = 255;
	
	return intensidad;
}
