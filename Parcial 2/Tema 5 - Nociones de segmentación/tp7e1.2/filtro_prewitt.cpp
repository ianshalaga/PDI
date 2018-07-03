#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat filtro_prewitt(const Mat &imagen,const int &nt) {
	
	Mat kernel_ph = prewitt_h();
	Mat kernel_pv = prewitt_v();
	Mat kernel_pd = prewitt_d();
	Mat kernel_pdi = prewitt_di();
	
	Mat imagen_ph = umbral(convolve(imagen,kernel_ph),nt);
	Mat imagen_pv = umbral(convolve(imagen,kernel_pv),nt);
	Mat imagen_pd = umbral(convolve(imagen,kernel_pd),nt);
	Mat imagen_pdi = umbral(convolve(imagen,kernel_pdi),nt);
	
	vector<Mat> mascaras = {imagen_ph,imagen_pv,imagen_pd,imagen_pdi};
	
	Mat lineas = or_mascaras(mascaras);
	
	return lineas;	
}
