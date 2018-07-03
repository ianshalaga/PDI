#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat mascara_difusa(const Mat &imagen,const Mat &kernel_pb) {
	
	return resta(imagen,convolve(imagen,kernel_pb));
	
}
