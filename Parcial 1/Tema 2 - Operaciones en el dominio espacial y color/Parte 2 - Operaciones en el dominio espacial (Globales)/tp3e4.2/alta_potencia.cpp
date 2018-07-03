#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat alta_potencia(const Mat imagen,const float A,const Mat kernel,const int version) {
	
	if (version == 1)
		return resta(A*imagen,convolve(imagen,kernel));
	else
		return suma((A-1)*imagen,convolve(imagen,kernel),0.5);
}
