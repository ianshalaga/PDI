#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat filtro_pa_sc_l(const Mat &imagen,const int &filas,const int &columnas,const int &nt) {
	
	Mat kernel_lh = filtro_pa_sc_lh(filas,columnas);
	Mat kernel_lv = filtro_pa_sc_lv(filas,columnas);
	Mat kernel_ld = filtro_pa_sc_ld(filas,columnas);
	Mat kernel_ldi = filtro_pa_sc_ldi(filas,columnas);
	
	Mat imagen_lh = umbral(convolve(imagen,kernel_lh),nt);
	Mat imagen_lv = umbral(convolve(imagen,kernel_lv),nt);
	Mat imagen_ld = umbral(convolve(imagen,kernel_ld),nt);
	Mat imagen_ldi = umbral(convolve(imagen,kernel_ldi),nt);
	
	vector<Mat> mascaras = {imagen_lh,imagen_lv,imagen_ld,imagen_ldi};
	
	Mat lineas = or_mascaras(mascaras);
	
	return lineas;
}
