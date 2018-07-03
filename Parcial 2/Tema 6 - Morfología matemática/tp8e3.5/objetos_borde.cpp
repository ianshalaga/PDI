#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat objetos_borde(const Mat &mascara) {
	
//	Mascara de bordes blancos para dilatar
	Mat borde(mascara.size(),CV_8UC(1),Scalar(0));
	
	int filas = mascara.rows;
	int columnas = mascara.cols;
	
	for(int i=0;i<columnas;i++) { 
		borde.at<uchar>(0,i) = 255;
		borde.at<uchar>(filas-1,i) = 255;
	}
	
	for(int i=0;i<filas;i++) { 
		borde.at<uchar>(i,0) = 255;
		borde.at<uchar>(i,columnas-1) = 255;
	}
	
//	Reconstruccion
	Mat ee = getStructuringElement(MORPH_CROSS,{3,3},Point(-1,-1));
	Mat borde_viejo(mascara.size(),CV_8UC(1),Scalar(0));
	
	while (norm(borde,borde_viejo,NORM_L2)>0) {
		borde_viejo = borde.clone();
		
		dilate(borde,borde,ee,Point(-1,-1),1);
		borde = and_mascaras({mascara,borde});
	}
	
	return borde;
}
