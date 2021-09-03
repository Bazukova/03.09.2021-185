#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	int height = 520;
	int width = 840;
	Mat img(height, width, CV_8UC3);
	Point textOrg(100, img.rows / 2);
	int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
	double fontScale = 2;
	Scalar color(200, 100, 50);
	putText(img, "OpenCV Step By", textOrg, fontFace, fontScale, color);
	//namedWindow("Hello World", 0);
	imshow("Hello World", img);
	waitKey(0);
	system("pause");
	return 0;
}