#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "vector"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

vector<Mat> mediana(vector<Mat> imagenes,int kernel) {
	
	for(int k=0;k<imagenes.size();k++) { 
		medianBlur(imagenes[k],imagenes[k],kernel);
	}
	
	return imagenes;
}
