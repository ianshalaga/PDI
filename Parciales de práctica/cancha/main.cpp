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

int main(int argc,char **argv) {
	
//	Carga de imagenes
//	Mat cancha = imread("1.png");
//	Mat cancha = imread("2.png");
//	Mat cancha = imread("3.png");
//	Mat cancha = imread("4.png");
//	Mat cancha = imread("5.png");
	Mat cancha = imread("6.png");
	
//	Carga de imagenes de publicidades
	Mat calco = imread("huang2.jpg");
	resize(calco,calco,{0,0},0.25,0.25,INTER_LINEAR);
	Mat calco2 = calco.clone();
	
//	Restauracion
	Mat cancha_rest;
	medianBlur(cancha,cancha_rest,3);
	
//	Separacion de canales
	Mat cancha_hsv;
	cvtColor(cancha_rest,cancha_hsv,CV_BGR2HSV);
	vector<Mat> cancha_hsv_vec;
	split(cancha_hsv,cancha_hsv_vec);
	
//	Histogramas
	Mat histoH = histogram(cancha_hsv_vec[0],256);
	Mat histoS = histogram(cancha_hsv_vec[1],256);
	Mat histoV = histogram(cancha_hsv_vec[2],256);

	histoH = draw_hist(histoH);
	histoS = draw_hist(histoS);
	histoV = draw_hist(histoV);
	
//	Posiciones de las lineas blancas de la cancha
	Mat cancha_gris = cancha_hsv_vec[2];
	Mat promedios_v = promedio_intensidad_v(cancha_gris);
	Mat promedios_h = promedio_intensidad_h(cancha_gris);
	threshold(promedios_v,promedios_v,160,255,THRESH_BINARY);
	threshold(promedios_h,promedios_h,225,255,THRESH_BINARY);
	vector<int> vector_v = blancos_v(promedios_h);
	vector<int> vector_h = blancos_h(promedios_v);
	
//	Pegado de publicidades
	Rect roi_pi(vector_h[0]-calco.cols-2,vector_v[1]+2,calco.cols,calco.rows);
	Rect roi_pd(vector_h[1],vector_v[1]+2,calco.cols,calco.rows);
	Rect roi_pc(((vector_h[1]-vector_h[0])/2)+vector_h[0]-calco.cols/2,cancha.rows-calco.rows-2,calco.cols,calco.rows);
	
	vector<Mat> vector_roi;
	split(cancha(roi_pc),vector_roi);
	
	vector_roi[0] = suma(calco,vector_roi[0],0.5);
	vector_roi[1] = suma(calco,vector_roi[1],0.5);
	vector_roi[2] = suma(calco,vector_roi[2],0.5);
	
	/*Ajuste de segmentacion a los valores de la cancha*/
//	Rect roi_pasto(0,vector_v[1],cancha.cols,cancha.rows-vector_v[1]);
//	Mat pastoH = cancha_hsv_vec[0]; //(roi_pasto);
	Mat pastoS = cancha_hsv_vec[1]; //(roi_pasto);
	
//	Mat mediaH,stdevH;
//	meanStdDev(pastoH,mediaH,stdevH);
//	int lim_supH = mediaH.at<double>(0,0)+stdevH.at<double>(0,0);
//	int lim_infH = mediaH.at<double>(0,0)-stdevH.at<double>(0,0);
	
	Mat mediaS,stdevS;
	meanStdDev(pastoS,mediaS,stdevS);
	int lim_supS = mediaS.at<double>(0,0)+stdevS.at<double>(0,0);
	int lim_infS = mediaS.at<double>(0,0)-stdevS.at<double>(0,0);
	
	Mat cancha_uH,cancha_uS;
//	cancha_uH = umbral_rango(cancha_hsv_vec[0],lim_infH,lim_supH);
	cancha_uS = umbral_rango(cancha_hsv_vec[1],lim_infS,lim_supS);
	
//	vector<Mat> mascaras = {cancha_uH,cancha_uS};
//	Mat cancha_u = or_mascaras(mascaras);
	
	Mat transparente;
	merge(vector_roi,transparente);
	
	calco.copyTo(cancha(roi_pi),cancha_uS(roi_pi));
	calco.copyTo(cancha(roi_pd),cancha_uS(roi_pd));
	transparente.copyTo(cancha(roi_pc),cancha_uS(roi_pc));
	
//	Presentacion de resultados
	vector<Mat> histogramas = {histoH,histoS,histoV};
	Mat mosaico_his = concatenar_v_gray(histogramas);
	
	vector<Mat> resultados = {cancha};
	Mat mosaico_res = concatenar_v_color(resultados);
	
	imwrite("resultados.png",mosaico_res);
	
//	Ventanas
	namedWindow("Imagenes originales",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagenes originales",mosaico_res); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("histogramas",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("histogramas",mosaico_his); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
