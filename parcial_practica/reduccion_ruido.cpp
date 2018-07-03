#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
//#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat reduccion_ruido(vector<Mat> ruidosas) {
	
	Mat reduccion_ruido(ruidosas[0].size(),CV_64F,Scalar(0));
	
	for(int k=0;k<ruidosas.size();k++) {
		Mat ruidosa;
		ruidosas[k].convertTo(ruidosa,CV_64F);
		reduccion_ruido = reduccion_ruido + ruidosa;
	}
	
	reduccion_ruido = reduccion_ruido/ruidosas.size();

	reduccion_ruido.convertTo(reduccion_ruido,CV_8UC(1));
	
	return reduccion_ruido;
}
