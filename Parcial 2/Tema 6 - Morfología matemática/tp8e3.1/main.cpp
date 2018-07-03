#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int main(int argc, char** argv) {
	
	Mat imagen = imread("Tarjeta.jpeg",CV_LOAD_IMAGE_GRAYSCALE);
	info(imagen);
	
	Mat doble;
	resize(imagen,doble,{0,0},2,2,CV_INTER_LINEAR);

	Mat borrosa;
	medianBlur(doble,borrosa,3);
	
	Mat imagen_u = umbral_negativo(borrosa,150);
	info(imagen_u);
	
	Mat ee = getStructuringElement(MORPH_RECT,{3,3},Point(-1,-1));
	print(ee,cout);

	Mat erosion;
	erode(imagen_u,erosion,ee,Point(-1,-1),2);

	Mat kernel_pb = filtro_pb(3,3);
	Mat erosion_u;
	erosion_u = umbral(convolve(erosion,kernel_pb),85);

	Mat dilatacion;
	dilate(erosion_u,dilatacion,ee,Point(-1,-1),10);
	
	Mat producto = multiplicacion(imagen_u,dilatacion);
	Mat resultado = umbral_negativo(producto,127);
//	resize(resultado,resultado,{0,0},0.5,0.5,CV_INTER_LINEAR);
	
//	resize(imagen_u,imagen_u,{0,0},0.5,0.5,CV_INTER_LINEAR);
	
	vector<Mat> imagenes = {imagen,imagen_u,resultado};
	Mat mosaico = concatenar_v_gray(imagenes);
	imwrite("tarjeta.png",mosaico);
	
	//	Ventanas
	namedWindow("Original - Umbralizada - Resultado",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Original - Umbralizada - Resultado",mosaico); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
