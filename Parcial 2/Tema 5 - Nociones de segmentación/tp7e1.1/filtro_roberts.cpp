#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat filtro_roberts(const Mat &imagen,const int &nt) {
	
	Mat kernel_rd = roberts_d();
	Mat kernel_rdi = roberts_di();
	
	Mat imagen_rd = umbral(convolve(imagen,kernel_rd),nt);
	Mat imagen_rdi = umbral(convolve(imagen,kernel_rdi),nt);
	
	vector<Mat> mascaras = {imagen_rd,imagen_rdi};
	
	Mat lineas = or_mascaras(mascaras);
	
	return lineas;
}
