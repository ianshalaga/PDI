#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int promedio_intensidad_mask(const Mat &imagen,const Mat &mascara) {
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	float suma = 0;
	float blancos = 0;
	
	for(int i=0;i<filas;i++) { 
		for(int j=0;j<columnas;j++) { 
			if (mascara.at<uchar>(i,j) == 255) {
				suma += imagen.at<uchar>(i,j);
				blancos += 1;
			}
		}
	}
	
	return suma/blancos;
}
