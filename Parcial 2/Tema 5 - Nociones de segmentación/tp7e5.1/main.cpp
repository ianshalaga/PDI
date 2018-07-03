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
	
	Mat corrientes = imread("corrientes_ruidogris.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	Mat iguazu = imread("iguazu_ruidogris.jpg",CV_LOAD_IMAGE_GRAYSCALE);

//	corrientes = rotate(corrientes,60);
//	iguazu = rotate(iguazu,60);
	
//	Presentacion de las imagenes originales
	vector<Mat> originales = {corrientes,iguazu};
	Mat conc_ori = concatenar_h_gray(originales);
	imwrite("conc_ori.png",conc_ori);
	
//	Restauracion
	Mat corrientes_sr,iguazu_sr;
	Mat kernel_gauss = gauss_kernel(3,0.9);
	corrientes_sr = convolve(corrientes,kernel_gauss);
	iguazu_sr = convolve(iguazu,kernel_gauss);
	medianBlur(corrientes_sr,corrientes_sr,3);
	medianBlur(iguazu_sr,iguazu_sr,3);
	
//	Mat corrientes_sr,iguazu_sr;
//	Mat kernel_gauss = gauss_kernel(3,0.9);
//	medianBlur(corrientes,corrientes_sr,3);
//	medianBlur(iguazu,iguazu_sr,3);
//	corrientes_sr = convolve(corrientes_sr,kernel_gauss);
//	iguazu_sr = convolve(iguazu_sr,kernel_gauss);
	
//	Presentacion de las imagenes restauradas
	vector<Mat> sin_ruido = {corrientes_sr,iguazu_sr};
	Mat conc_sr = concatenar_h_gray(sin_ruido);
	imwrite("conc_sr.png",conc_sr);
	
//	Resaltado de la pista de aterrizaje
	Mat lut_table(256,1,CV_8UC(1),Scalar(255)); //imagen de una dimension
	
	float gamma_pot = 6;
	float gamma_raiz = 2;
	pot_raiz(lut_table,gamma_pot,gamma_raiz,127);
	
	Mat transformacion = draw_graph(lut_table);
	imwrite("transformacion.png",transformacion);
	
	Mat corrientes_potencia,iguazu_potencia;
	LUT(corrientes_sr,lut_table,corrientes_potencia);
	LUT(iguazu_sr,lut_table,iguazu_potencia);

//	Presentacion de las imagenes resaltadas
	vector<Mat> potencia = {corrientes_potencia,iguazu_potencia};
	Mat conc_potencia = concatenar_h_gray(potencia);
	imwrite("conc_potencia.png",conc_potencia);
	
//	Deteccion de bordes
	Mat kernel_pa = filtro_pa(3,3,0);
	Mat corrientes_bordes = convolve(corrientes_potencia,kernel_pa);
	Mat iguazu_bordes = convolve(iguazu_potencia,kernel_pa);
	
//	Presentacion de los bordes
	vector<Mat> bordes = {corrientes_bordes,iguazu_bordes};
	Mat conc_bordes = concatenar_h_gray(bordes);
	imwrite("conc_bordes.png",conc_bordes);
	
//	Umbralizado
	int corrientes_promedio = promedio_intensidad(corrientes_potencia);
	int iguazu_promedio = promedio_intensidad(iguazu_potencia);
	
	Mat corrientes_umbral = umbral(corrientes_bordes,100);
	Mat iguazu_umbral = umbral(iguazu_bordes,100);

//	Presentacion de los bordes
	vector<Mat> mascaras = {corrientes_umbral,iguazu_umbral};
	Mat conc_umbral = concatenar_h_gray(mascaras);
	imwrite("conc_umbral.png",conc_umbral);
	
//	Hough
	Mat corrientes_pista,iguazu_pista;
	cvtColor(corrientes_sr,corrientes_pista,CV_GRAY2BGR);
	cvtColor(iguazu_sr,iguazu_pista,CV_GRAY2BGR);
	
	vector<Vec4i> corrientes_lineas,iguazu_lineas;
	HoughLinesP(corrientes_bordes,corrientes_lineas,1,CV_PI/180,150,0,2);
	HoughLinesP(iguazu_bordes,iguazu_lineas,1,CV_PI/180,100,0,5);
	
	for(size_t i=0;i<1/*lineas.size()*/;i++) {
		Vec4i l = corrientes_lineas[i];
		line(corrientes_pista,Point(l[0],l[1]),Point(l[2],l[3]),Scalar(0,0,255),3,CV_AA);
	}
	
	for(size_t i=0;i<1/*lineas.size()*/;i++) {
		Vec4i l = iguazu_lineas[i];
		line(iguazu_pista,Point(l[0],l[1]),Point(l[2],l[3]),Scalar(0,0,255),3,CV_AA);
	}
	
//	vector<Vec2f> corrientes_lineas,iguazu_lineas;
//	HoughLines(corrientes_bordes,corrientes_lineas,1,CV_PI/180,50);
//	HoughLines(iguazu_bordes,iguazu_lineas,1,CV_PI/180,50);
//	
//	for( size_t i = 0; i < 1/*lineas1.size()*/; i++ ) {
//		float rho = corrientes_lineas[i][0];
//		float theta = corrientes_lineas[i][1];
//		double a = cos(theta), b = sin(theta);
//		double x0 = a*rho, y0 = b*rho;
//		Point pt1(cvRound(x0 + 1000*(-b)),
//				  cvRound(y0 + 1000*(a)));
//		Point pt2(cvRound(x0 - 1000*(-b)),
//				  cvRound(y0 - 1000*(a)));
//		line(corrientes_pista,pt1,pt2,Scalar(0,0,255),3,8);
//	}
	
//	for( size_t i = 0; i < 1/*lineas1.size()*/; i++ ) {
//		float rho = iguazu_lineas[i][0];
//		float theta = iguazu_lineas[i][1];
//		double a = cos(theta), b = sin(theta);
//		double x0 = a*rho, y0 = b*rho;
//		Point pt1(cvRound(x0 + 1000*(-b)),
//				  cvRound(y0 + 1000*(a)));
//		Point pt2(cvRound(x0 - 1000*(-b)),
//				  cvRound(y0 - 1000*(a)));
//		line(iguazu_pista,pt1,pt2,Scalar(0,0,255),3,8);
//	}
	
//	Presentacion de las pistas coloreadas	
	vector<Mat> pistas = {corrientes_pista,iguazu_pista};
	Mat conc_pistas = concatenar_h_color(pistas);
	imwrite("conc_pistas.png",conc_pistas);
	
//	Presentacion final
	vector<Mat> resultados = {conc_ori,conc_sr,conc_potencia,conc_bordes,conc_umbral,conc_pistas};
	Mat conc_final = concatenar_v_gray(resultados);
	imwrite("resultados.png",conc_final);
	
//	Ventanas
	namedWindow("Originales",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Originales",conc_ori); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Sin ruido",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Sin ruido",conc_sr); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Transformacion",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Transformacion",transformacion); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Potencia",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Potencia",conc_potencia); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Umbral",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Umbral",conc_bordes); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Umbral",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Umbral",conc_umbral); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Pistas",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Pistas",conc_pistas); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
