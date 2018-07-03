#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

//	r: valor de entrada, formato {0,...,...,...,255}
//	s: valor de salida, formato {0,...,...,...,255}

Mat transformacion_tramos(Mat lut_table,vector<float> r,vector<float> s) {
	
	for (int t=0;t<r.size()-1;t++) {
		float m = (s[t+1]-s[t])/(r[t+1]-r[t]);
		for (int i=r[t];i<r[t+1];i++) {
			lut_table.at<uchar>(i,0) = ajuste(m*(i-r[t]))+s[t];
		}		
	}
	
	return lut_table;
}
