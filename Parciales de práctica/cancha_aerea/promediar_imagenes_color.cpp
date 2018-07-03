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

Mat promediar_imagenes_color(vector<Mat> imagenes) {
	
	int cantidad = imagenes.size();
	
	Mat promedio1(imagenes[0].size(),CV_64F,Scalar(0));
	Mat promedio2(imagenes[0].size(),CV_64F,Scalar(0));
	Mat promedio3(imagenes[0].size(),CV_64F,Scalar(0));
	
	for(int k=0;k<imagenes.size();k++) {
		Mat imagen = imagenes[k];
		vector<Mat> vector_bgr;
		split(imagen,vector_bgr);
		Mat imagenB,imagenG,imagenR;
		vector_bgr[0].convertTo(imagenB,CV_64F);
		vector_bgr[1].convertTo(imagenG,CV_64F);
		vector_bgr[2].convertTo(imagenR,CV_64F);
		promedio1 = promedio1 + imagenB;
		promedio2 = promedio2 + imagenG;
		promedio3 = promedio3 + imagenR;
	}
	
	promedio1 = promedio1/cantidad;
	promedio2 = promedio2/cantidad;
	promedio3 = promedio3/cantidad;
	
	promedio1.convertTo(promedio1,CV_8UC(1));
	promedio2.convertTo(promedio2,CV_8UC(1));
	promedio3.convertTo(promedio3,CV_8UC(1));
	
	Mat promedio;
	vector<Mat> promedios = {promedio1,promedio2,promedio3};
	merge(promedios,promedio);
	
	return promedio;
}
