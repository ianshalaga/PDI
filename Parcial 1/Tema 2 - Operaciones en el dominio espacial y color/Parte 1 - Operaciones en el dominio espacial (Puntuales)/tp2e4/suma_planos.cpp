#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "bitset"
//#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

vector<Mat> suma_planos(vector<Mat> planos) {
	
	vector<Mat> suma(planos.size());
	
	suma[0] = planos[7];
	suma[1] = planos[7] + planos[6];
	suma[2] = planos[7] + planos[6] + planos[5];
	suma[3] = planos[7] + planos[6] + planos[5] + planos[4];
	suma[4] = planos[7] + planos[6] + planos[5] + planos[4] + planos[3];
	suma[5] = planos[7] + planos[6] + planos[5] + planos[4] + planos[3] + planos[2];
	suma[6] = planos[7] + planos[6] + planos[5] + planos[4] + planos[3] + planos[2] + planos[1];
	suma[7] = planos[7] + planos[6] + planos[5] + planos[4] + planos[3] + planos[2] + planos[1] + planos[0];
	
	return suma;
}
