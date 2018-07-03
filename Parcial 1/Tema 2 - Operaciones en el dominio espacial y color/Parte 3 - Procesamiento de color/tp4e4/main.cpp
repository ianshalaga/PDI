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
	Mat imagen = imread("futbol.jpg"); // Carga una imagen
	info(imagen); //Muestra información la imagen
	
	Mat ROI = imread("futbol_ROI.jpg");
	
//	Mascaras
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	Mat mascaraB(filas,columnas,CV_8UC(1));
	Mat mascaraG(filas,columnas,CV_8UC(1));
	Mat mascaraR(filas,columnas,CV_8UC(1));
	vector<Mat> mascara = {mascaraB,mascaraG,mascaraR};
	
	Mat mascaraH(filas,columnas,CV_8UC(1));
	Mat mascaraS(filas,columnas,CV_8UC(1));
	Mat mascaraV(filas,columnas,CV_8UC(1));
	vector<Mat> mascara_hsv = {mascaraH,mascaraS,mascaraV};
	
//	RGB
	
	vector<Mat> bgr_roi; // vector RBG
	split(ROI,bgr_roi); // Separación RGB
	
	int p_b = promedio(bgr_roi[0]);
	int p_g = promedio(bgr_roi[1]);
	int p_r = promedio(bgr_roi[2]);
	
	int radio_bgr = 40;
	
	vector<Mat> bgr_vector; // vector RBG
	split(imagen,bgr_vector); // Separación RGB
	
	inRange(bgr_vector[0],p_b-radio_bgr,p_b+radio_bgr,mascaraB);
	inRange(bgr_vector[1],p_g-radio_bgr,p_g+radio_bgr,mascaraG);
	inRange(bgr_vector[2],p_r-radio_bgr,p_r+radio_bgr,mascaraR);
	
	segmentar(bgr_vector,mascara);
	
	Mat histoB = draw_hist(histogram(bgr_roi[0],256));
	Mat histoG = draw_hist(histogram(bgr_roi[1],256));
	Mat histoR = draw_hist(histogram(bgr_roi[2],256));
	
	Mat salidaBGR; // Imagen de Salida RBG
	merge(bgr_vector,salidaBGR); // Union RGB
	
//	HSV
	
	Mat roiHSV;
	cvtColor(ROI,roiHSV,CV_BGR2HSV); // Conversion BGR -> HSV
	vector<Mat> hsv_roi; // vector RBG
	split(roiHSV,hsv_roi); // Separación RGB
	
	int p_h = promedio(hsv_roi[0]);
	int p_s = promedio(hsv_roi[1]);
	
	cout<<p_h<<"\n";
	cout<<p_s<<"\n";
	
	Mat imagenHSV; // Para trabajar
	cvtColor(imagen,imagenHSV,CV_BGR2HSV); // Conversion BGR -> HSV
	vector<Mat> hsv_vector; //vector HSV
	split(imagenHSV,hsv_vector); // Separacion HSV
	
	Mat histoH = draw_hist(histogram(hsv_roi[0],256));
	Mat histoS = draw_hist(histogram(hsv_roi[1],256));
	Mat histoV = draw_hist(histogram(hsv_roi[2],256));
	
	inRange(hsv_vector[0],p_h-5,p_h+5,mascara_hsv[0]);
	inRange(hsv_vector[1],p_s-50,p_s+50,mascara_hsv[1]);
	inRange(hsv_vector[2],0,255,mascara_hsv[2]);
	
	segmentar(hsv_vector,mascara_hsv);
	
	Mat imagenBGR; // Para mostrar el resultado final
	merge(hsv_vector,imagenHSV); // Union HSV
	cvtColor(imagenHSV,imagenBGR,CV_HSV2BGR); // Conversion HSV -> BGR
	
//	Ventanas de muestra
	
	namedWindow("Imagen de entrada",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen de entrada",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("ROI",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("ROI",ROI); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Procesamiento BGR",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Procesamiento BGR",salidaBGR); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Procesamiento HSV",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Procesamiento HSV",imagenBGR); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("B",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("B",histoB); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("G",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("G",histoG); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("R",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("R",histoR); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("H",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("H",histoH); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("S",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("S",histoS); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
//	namedWindow("V",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("V",histoV); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
