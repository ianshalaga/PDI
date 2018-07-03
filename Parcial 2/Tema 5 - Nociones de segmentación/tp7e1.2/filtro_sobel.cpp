#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat filtro_sobel(const Mat &imagen,const int &nt) {
	
	Mat kernel_sh = sobel_h();
	Mat kernel_sv = sobel_v();
	Mat kernel_sd = sobel_d();
	Mat kernel_sdi = sobel_di();
	
	Mat imagen_sh = umbral(convolve(imagen,kernel_sh),nt);
	Mat imagen_sv = umbral(convolve(imagen,kernel_sv),nt);
	Mat imagen_sd = umbral(convolve(imagen,kernel_sd),nt);
	Mat imagen_sdi = umbral(convolve(imagen,kernel_sdi),nt);
	
	vector<Mat> mascaras = {imagen_sh,imagen_sv,imagen_sd,imagen_sdi};
	
	Mat lineas = or_mascaras(mascaras);
	
	return lineas;	
}
