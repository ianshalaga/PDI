#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int porcentaje_llenado(const Mat &llena,const Mat &liquido) {
	
	int filas = llena.rows;
	int columnas = llena.cols;
	
	float suma_llena = 0;
	float suma_liquido = 0;
	
	for(int i=0;i<filas;i++) { 
		for(int j=0;j<columnas;j++) {
			if (llena.at<uchar>(i,j) == 255)
				suma_llena += 1;
			if (liquido.at<uchar>(i,j) == 255)
				suma_liquido += 1;
		}
	}
	
	return 100- (suma_liquido*100/suma_llena);
}
