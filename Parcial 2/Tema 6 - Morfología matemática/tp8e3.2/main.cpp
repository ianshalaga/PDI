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
	
	Mat imagen = imread("Caracteres.jpeg",CV_LOAD_IMAGE_GRAYSCALE);
	info(imagen);
		
//	Ampliacion, restauración y umbralizacion
	Mat ampliacion;
	resize(imagen,ampliacion,{0,0},2,2,CV_INTER_LINEAR);
	
	Mat mediana;
	medianBlur(ampliacion,mediana,3);
	
	Mat imagen_u = umbral_negativo(mediana,150);
	info(imagen_u);
	
//	Morfologia
	Mat ee = getStructuringElement(MORPH_RECT,{3,3},Point(-1,-1));
	print(ee,cout);
	
	Mat erosion;
	erode(imagen_u,erosion,ee,Point(-1,-1),2);

	Mat dilatacion;
	dilate(erosion,dilatacion,ee,Point(-1,-1),2);
	resize(dilatacion,dilatacion,{0,0},0.5,0.5,CV_INTER_LINEAR);
	
//	Extraccion de las letras
	Mat blanco(imagen.size(),CV_8UC(1),Scalar(255));
	Mat let = multiplicacion(imagen,dilatacion);
	Mat dilatacion_inv = umbral_negativo(dilatacion,127);
	Mat simb = multiplicacion(blanco,dilatacion_inv);
	Mat letras = 2*suma(let,simb,0.5);
	
//	Extraccion de simbolos
	Mat simbolos = 2*resta(imagen,letras);
	
//	Presentacion de resultados
	vector<Mat> imagenes = {imagen,letras,simbolos};	
	Mat mosaico = concatenar_v_gray(imagenes);
	
	imwrite("letras_simbolos.png",mosaico);
	
//	Ventanas
	namedWindow("Resultados",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Resultados",mosaico); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
