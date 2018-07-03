#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat filtro_pa_sc_ld(const int &filas,const int &columnas) {
	
	Mat kernel(filas,columnas,CV_64F,Scalar(-1));
	
	for(int i=0;i<filas;i++) {
		for(int j=0;j<columnas;j++) {
			if (i == j)
				kernel.at<double>(i,j) = 2;
		}
	}
	
	return kernel;
}

Mat filtro_pa_sc_ldi(const int &filas,const int &columnas) {
	
	Mat kernel(filas,columnas,CV_64F,Scalar(-1));
	
	kernel.at<double>(0,2) = 2;
	kernel.at<double>(1,1) = 2;
	kernel.at<double>(2,0) = 2;
	
	return kernel;
}

Mat filtro_pa_sc_lh(const int &filas,const int &columnas) {
	
	Mat kernel(filas,columnas,CV_64F,Scalar(-1));
	
	for(int i=0;i<columnas;i++) { 
		kernel.at<double>(filas/2,i) = 2;
	}
	
	return kernel;
}

Mat filtro_pa_sc_lv(const int &filas,const int &columnas) {
	
	Mat kernel(filas,columnas,CV_64F,Scalar(-1));
	
	for(int i=0;i<columnas;i++) { 
		kernel.at<double>(i,columnas/2) = 2;
	}
	
	return kernel;
}

Mat filtro_pa_sc_l(const Mat &imagen,const int &filas,const int &columnas) {
	
	Mat kernel_lh = filtro_pa_sc_lh(filas,columnas);
	Mat kernel_lv = filtro_pa_sc_lv(filas,columnas);
	Mat kernel_ld = filtro_pa_sc_ld(filas,columnas);
	Mat kernel_ldi = filtro_pa_sc_ldi(filas,columnas);
	
	Mat imagen_lh,imagen_lv,imagen_ld,imagen_ldi;
	threshold(convolve(imagen,kernel_lh),imagen_lh,0,255,THRESH_OTSU|THRESH_BINARY);
	threshold(convolve(imagen,kernel_lv),imagen_lv,0,255,THRESH_OTSU|THRESH_BINARY);
	threshold(convolve(imagen,kernel_ld),imagen_ld,0,255,THRESH_OTSU|THRESH_BINARY);
	threshold(convolve(imagen,kernel_ldi),imagen_ldi,0,255,THRESH_OTSU|THRESH_BINARY);
	
	vector<Mat> mascaras = {imagen_lh,imagen_lv,imagen_ld,imagen_ldi};
	Mat lineas = or_mascaras(mascaras);
	
	return lineas;
}
