#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat rellenar(Mat mascara) {
	
	Mat mascara_inv = umbral_negativo(mascara,127);
	
	int filas = mascara.rows;
	int columnas = mascara.cols;

	Mat F(mascara.size(),CV_8UC(1),Scalar(0));
	
	for(int i=0;i<columnas;i++) { 
		F.at<uchar>(0,i) = 255;
		F.at<uchar>(filas-1,i) = 255;
	}
	
	for(int i=0;i<filas;i++) { 
		F.at<uchar>(i,0) = 255;
		F.at<uchar>(i,columnas-1) = 255;
	}
	
//	F = and_mascaras({mascara_inv,F});
	
	Mat ee = getStructuringElement(MORPH_CROSS,{3,3},Point(-1,-1));
	Mat F_viejo(mascara.size(),CV_8UC(1),Scalar(0));
	
	while (norm(F,F_viejo,NORM_L2)>0) {
		F_viejo = F.clone();
		
		dilate(F,F,ee,Point(-1,-1),1);
		F = and_mascaras({mascara_inv,F});
		
		imshow("F",F);
		waitKey();
	}
	
	F = umbral_negativo(F,127);
	
	return F;
}
