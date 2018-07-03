#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

vector<Mat> imagenes_ruidosas(Mat imagen,int cantidad,float media,float stdev) {
	
	vector<Mat> ruidosas(cantidad);
	
	for(int i=0;i<ruidosas.size();i++) { 
		ruidosas[i] = ruido_gaussiano(imagen,0,0.05);
	}
	
	return ruidosas;
}
