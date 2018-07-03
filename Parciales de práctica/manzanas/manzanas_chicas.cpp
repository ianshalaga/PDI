#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat manzanas_chicas(Mat mascara) {
	
	Mat cc_todas,est_todas,cen_todas;
	connectedComponentsWithStats(mascara,cc_todas,est_todas,cen_todas);
	
	cc_todas.convertTo(cc_todas,CV_8UC(1));
	
	int suma = 0;
	for(int i=1;i<est_todas.rows;i++) { 
		suma += est_todas.at<int>(i,4);
	}
	suma = float(suma)/(est_todas.rows-1);
//	cout<<suma<<"\n";
	
	Mat negro(mascara.size(),CV_8UC(1),Scalar(0));
	Mat azules(mascara.size(),CV_8UC(1),Scalar(0));
	
	for(int k=1;k<est_todas.rows;k++) { 
		if (est_todas.at<int>(k,4) < suma) {
			azules = cambiar_valor(cc_todas,k);
		}
		negro = or_mascaras({negro,azules});
	}
	
	return negro;
}
