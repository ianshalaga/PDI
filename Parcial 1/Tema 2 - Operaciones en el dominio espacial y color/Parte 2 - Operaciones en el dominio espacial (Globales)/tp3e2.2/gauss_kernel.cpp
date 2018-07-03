#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat gauss_kernel(const int &dimension,const float &stdev) {
	
	Mat kernel_col = getGaussianKernel(dimension,stdev,CV_64F);
	Mat kernel_fil = kernel_col.t();
	Mat kernel_gau = kernel_col*kernel_fil;
	
	return kernel_gau;
}
