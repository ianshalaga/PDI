#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "vector"
#include "pdi_functions.h"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int main(int argc, char** argv) {
	
	Mat imagen = imread("huang2.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	
	Mat kernel = filtro_pb(3,3);
	Mat mask_dif = mascara_difusa(imagen,kernel);
	
//	Presentacion de resultados
	vector<Mat> resultados = {imagen,mask_dif};
	Mat mosaico_res = concatenar_imagenes(resultados,true,true);
	
	imwrite("mascara_difusa.png",mosaico_res);
	
	//	Ventanas
	namedWindow("Resultados",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Resultados",mosaico_res); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
