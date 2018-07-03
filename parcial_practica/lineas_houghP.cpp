#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat lineas_houghP(const Mat &bordes,const vector<Vec4i> &ini_fin) {
	
	Mat bordes_color;
	cvtColor(bordes,bordes_color,CV_GRAY2BGR);
	
	for(size_t i=0;i<ini_fin.size();i++) {
		Vec4i l = ini_fin[i];
		line(bordes_color,Point(l[0],l[1]),Point(l[2],l[3]),Scalar(0,0,255),3,CV_AA);
	}
	
	return bordes_color;
}
