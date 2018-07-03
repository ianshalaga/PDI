#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat cierre(const Mat &imagen,const Mat &elem_estruc) {
	
	Mat cr;
	erode(imagen,cr,elem_estruc,Point(-1,-1));
	dilate(cr,cr,elem_estruc,Point(-1,-1));
	
	return cr;
}
