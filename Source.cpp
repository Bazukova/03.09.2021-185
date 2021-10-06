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
	Mat img(height, width, CV_8UC3);  //создаётся матрица(Mat) изображение заданной ширены и высоты с 3-х канальным цветом
	Point textOrg(100, img.rows / 2);  //изменение положения текста по вертикали
	int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX; //настройка шрифта , FONT_HERSHEY_SIMPLEX - тип шрифта
	double fontScale = 2; 
	Scalar color(200, 100, 50); //цвет текста
	putText(img, "OpenCV Step By", textOrg, fontFace, fontScale, color);
	//namedWindow("Hello World", 0);
	imshow("Hello World", img); //открывает окно
	waitKey(0);
	system("pause");
	return 0;
}
