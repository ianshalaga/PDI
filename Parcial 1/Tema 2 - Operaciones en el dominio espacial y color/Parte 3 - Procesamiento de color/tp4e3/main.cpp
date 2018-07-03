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
	//carga una imagen
//	Mat imagen=imread("camino.tif");
	Mat imagen=imread("flowers_oscura.tif");
//	Mat imagen=imread("chairs_oscura.jpg");
	Mat original=imread("chairs.jpg");
	
	//Muestra información la imagen
	info(imagen);

//	Mat kernel = filtro_pa(3,3,1);
//	print(kernel,cout);
	
	Mat histograma = draw_hist(histogram(imagen,256));

	vector<Mat> bgr_vector;
	split(imagen,bgr_vector);
	equalizeHist(bgr_vector[0],bgr_vector[0]);
	equalizeHist(bgr_vector[1],bgr_vector[1]);
	equalizeHist(bgr_vector[2],bgr_vector[2]);
	
//	bgr_vector[0] = convolve(bgr_vector[0],kernel);
//	bgr_vector[1] = convolve(bgr_vector[1],kernel);
//	bgr_vector[2] = convolve(bgr_vector[2],kernel);
	
	Mat salida;
	merge(bgr_vector,salida);
	
	Mat histograma_ec = draw_hist(histogram(salida,256));
	
	Mat imagenHSV; // Para trabajar
	cvtColor(imagen,imagenHSV,CV_BGR2HSV);
	vector<Mat> hsv_vector;
	split(imagenHSV,hsv_vector);

	equalizeHist(hsv_vector[1],hsv_vector[1]);
	equalizeHist(hsv_vector[2],hsv_vector[2]);
	
//	hsv_vector[1] = convolve(hsv_vector[1],kernel);
//	hsv_vector[2] = convolve(hsv_vector[2],kernel);
	
	Mat imagenBGR; // Para mostrar el resultado final
	merge(hsv_vector,imagenHSV);
	cvtColor(imagenHSV,imagenBGR,CV_HSV2BGR);
	
//	namedWindow("Kernel",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("Kernel",kernel); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Imagen original",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen original",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("histograma",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("histograma",histograma); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Ecualizada",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Ecualizada",salida); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Histograma Ecualizada",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Histograma Ecualizada",histograma_ec); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Imagen BGR",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen BGR",imagenBGR); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Original",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Original",original); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("H",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("H",hsv_vector[0]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("S",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("S",hsv_vector[1]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("V",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("V",hsv_vector[2]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
