#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "opencv2/opencv.hpp"

struct video_properties{
	int fps;
	int fourcc;
	cv::Size frame_size;
};

void usage(const char *program, std::ostream &out = std::cerr){
	out << program << " video_file " << " n " << " prefix\n";
	out << "Extract n frames from video_file and store each image with prefix\n";
}

int main(int argc, char **argv){
	if(argc not_eq 4){
		usage(argv[0]);
		return 1;
	}
	
	cv::VideoCapture video(argv[1]);
	int count = std::stoi(argv[2]);
	int total_frames = video.get(CV_CAP_PROP_FRAME_COUNT);
	int step = total_frames/count;
	
	for(int K=step/2, i=0; K<total_frames; K+=step, ++i){
		video.set(CV_CAP_PROP_POS_FRAMES, K);
		cv::Mat frame;
		video >> frame;
		
		std::stringstream s;
		s << argv[3] << std::setfill('0') << std::setw(3) << i << ".jpg";
		std::cout << "writting " << s.str() << '\n';
		cv::imwrite(s.str(), frame);
	}
	
	return 0;
}

