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

vector<int> porcentaje_llenado(Mat imagen_llenas,vector<int> no_llenas) {
	vector<int> porcentaje_llenado(no_llenas.size()/2);
	vector<int> prom_llenas = promedio_intensidad(imagen_llenas,no_llenas);
	for (int i=0;i<prom_llenas.size();i++) {
		porcentaje_llenado[i] = prom_llenas[i]*100/222;
	}
	return porcentaje_llenado;
}
