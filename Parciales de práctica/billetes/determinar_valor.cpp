#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int determinar_valor(int rombos) {
	
	int valor;
	
	if (rombos == 6)
		valor = 2;
	else if (rombos == 5)
		valor = 5;
	else if (rombos == 4)
		valor = 10;
	else if (rombos == 3)
		valor = 20;
	else if (rombos == 2)
		valor = 50;
	else if (rombos == 1)
		valor = 100;
	
	return valor;
}
