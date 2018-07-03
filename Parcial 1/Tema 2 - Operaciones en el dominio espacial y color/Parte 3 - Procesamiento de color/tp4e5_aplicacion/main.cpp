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
	Mat imagen = imread("Deforestacion.png"); // Carga una imagen
	info(imagen); //Muestra información la imagen
	
	Mat kernel = filtro_pb(5,5);
	Mat kernel2 = filtro_pb(5,5);
//	print(kernel,cout);
		
//	----------------------------------------------------------
//	Proceso de recorte de la zona encerrada por el rectangulo
	
	Mat imagenHSV; // Para trabajar
	cvtColor(imagen,imagenHSV,CV_BGR2HSV); // Conversion BGR -> HSV
	vector<Mat> hsv_vector; //vector HSV
	split(imagenHSV,hsv_vector); // Separacion HSV
	
	Mat perfil_v_u = umbral(achatar_v(hsv_vector[2]),160);
	Mat perfil_h_u = umbral(achatar_h(hsv_vector[2]),160);
	
//	imwrite("achatamiento vertical binarizado.png",perfil_v_u);
//	imwrite("achatamiento horizontal binarizado.png",perfil_h_u);
	
	vector<int> rec_x = recuadro_x(perfil_v_u);
	vector<int> rec_y = recuadro_y(perfil_h_u);
	
	Mat recorteH = recortar(hsv_vector[0],rec_x,rec_y);
	Mat recorteS = recortar(hsv_vector[1],rec_x,rec_y);
	Mat recorteV = recortar(hsv_vector[2],rec_x,rec_y);
	
	vector<Mat> recorte_hsv = {recorteH,recorteS,recorteV};
	
	Mat area_interes_hsv; // Para mostrar el resultado final
	Mat area_interes_bgr;
	merge(recorte_hsv,area_interes_hsv); // Union HSV
	cvtColor(area_interes_hsv,area_interes_bgr,CV_HSV2BGR); // Conversion HSV -> BGR
	
//	imwrite("recorte.png",area_interes_bgr);
	
	area_interes_hsv = convolve(area_interes_hsv,kernel2);
	
	vector<Mat> recorte_hsv2;
	split(area_interes_hsv,recorte_hsv2);
	
//	cvtColor(area_interes_hsv,area_interes_bgr,CV_HSV2BGR);
//	imwrite("recorte_suavizado.png",area_interes_bgr);
	
//	----------------------------------------------------------
//	Proceso de segmentacion de la zona deforestada
	
	Mat ROI = imread("bosque2.png");
	
	int filas = recorte_hsv[0].rows;
	int columnas = recorte_hsv[0].cols;
	
	Mat mascaraH(filas,columnas,CV_8UC(1));
	Mat mascaraS(filas,columnas,CV_8UC(1));
	Mat mascaraV(filas,columnas,CV_8UC(1));
	vector<Mat> mascara_hsv = {mascaraH,mascaraS,mascaraV};
	
	Mat roiHSV;
	cvtColor(ROI,roiHSV,CV_BGR2HSV); // Conversion BGR -> HSV
	vector<Mat> hsv_roi; // vector RBG
	split(roiHSV,hsv_roi); // Separación RGB

	Mat histoH = draw_hist(histogram(hsv_roi[0],256));
	Mat histoS = draw_hist(histogram(hsv_roi[1],256));
	Mat histoV = draw_hist(histogram(hsv_roi[2],256));
	
//	imwrite("histograma subdominio H.png",histoH);
//	imwrite("histograma subdominio S.png",histoS);
//	imwrite("histograma subdominio V.png",histoV);
	
	int p_h = promedio(hsv_roi[0]);
	int p_s = promedio(hsv_roi[1]);
	
	cout<<p_h<<"\n";
	cout<<p_s<<"\n";
	
	inRange(recorte_hsv2[0],p_h-10,p_h+10,mascara_hsv[0]);
	inRange(recorte_hsv2[1],p_s-37,p_s+37,mascara_hsv[1]);
	inRange(recorte_hsv2[2],0,255,mascara_hsv[2]);
	
//	imwrite("mascara H.png",mascara_hsv[0]);
//	imwrite("mascara S.png",mascara_hsv[1]);
	
//	imwrite("mascara H suavizada.png",convolve(mascara_hsv[0],kernel));
//	imwrite("mascara S suavizada.png",convolve(mascara_hsv[1],kernel));
	
	mascara_hsv[0] = umbral(convolve(mascara_hsv[0],kernel),10);
	mascara_hsv[1] = umbral(convolve(mascara_hsv[1],kernel),10);
	
//	imwrite("mascara H suavizada binarizada.png",mascara_hsv[0]);
//	imwrite("mascara S suavizada binarizada.png",mascara_hsv[1]);
	
	Mat mask = 255-and_mascaras(mascara_hsv,0);
	
//	imwrite("mascaras intersectadas.png",mask);
	
	mascara_hsv[0] = 255-umbral(convolve(mask,kernel),250);
	mascara_hsv[1] = 255-umbral(convolve(mask,kernel),250);
	mascara_hsv[2] = 255-umbral(convolve(mask,kernel),250);
	
//	imwrite("mascaras intersectadas suavizadas.png",convolve(mask,kernel));
//	imwrite("mascaras intersectadas suavizadas binarizadas.png",mascara_hsv[0]);
	
	segmentar(recorte_hsv,mascara_hsv);
	
	int area_deforestada = superficie(mask,255);
	int area_forestada = superficie(mask,0);
	int area_total = area_deforestada + area_forestada;
	int at = filas*columnas;
	
	cout<<area_deforestada<<"\n";
	cout<<area_forestada<<"\n";
	cout<<area_total<<"\n";
	cout<<at<<"\n";
	
	Mat imagenBGR; // Para mostrar el resultado final
	merge(recorte_hsv,imagenHSV); // Union HSV
	cvtColor(imagenHSV,imagenBGR,CV_HSV2BGR); // Conversion HSV -> BGR
	
//	imwrite("resultado2.png",imagenBGR);
	
//	----------------------------------------------------------
//	Ventanas de muestra
	
	namedWindow("Imagen de entrada",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen de entrada",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Area de interes",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Area de interes",mask); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
//	namedWindow("Salida BGR",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("Salida BGR",salidaBGR); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
//	
//	namedWindow("Mascara S",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("Mascara S",mascara_hsv[1]); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
//	
//	namedWindow("Mascara V",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("Mascara V",mascara_hsv[2]); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Procesamiento HSV",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Procesamiento HSV",imagenBGR); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Histograma H",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Histograma H",histoH); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Histograma S",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Histograma S",histoS); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Histograma V",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Histograma V",histoV); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
//	namedWindow("H",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("H",mascara_hsv[0]); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
//	namedWindow("S",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("S",mascara_hsv[1]); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
//	namedWindow("V",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("V",mascara_hsv[2]); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
