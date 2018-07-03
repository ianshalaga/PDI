#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat pot_raiz(Mat lut_table,const float &gamma_pot,const float &gamma_raiz,const float &n_t) {
	
//	n_t: nivel de transicion
	
	float c_pot = n_t/pow(n_t,gamma_pot);
	
	for (int r=0;r<n_t;r++) {
		lut_table.at<uchar>(r,0) = ajuste(c_pot*pow(r,gamma_pot));
	}
	
	float c_raiz = float(255-n_t)/pow(float(255-n_t),1./gamma_raiz);
	
	for(int r=n_t;r<lut_table.rows;r++) {
		int ra = r - n_t;
		lut_table.at<uchar>(r,0) = ajuste(n_t+c_raiz*pow(ra,1./gamma_raiz));
	}
	
	return lut_table;
}
