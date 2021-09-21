#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace cv;
using namespace std;
Mat img;
int main()
{
	
	setlocale(LC_ALL, "Russian");
	char filename[80]; // ash.jpg
	cout << "Введите имя файла, в которой хотите внести изменения, и нажимте Enter" << endl;
	cin.getline(filename, 80);
	cout << "Открыть файл";
	cout << filename << endl;
	Mat img = imread(filename, 1);
	namedWindow("source_window", WINDOW_AUTOSIZE);
	imshow("source_window", img);
	Mat src_gray, canny_output;
	cvtColor(img, src_gray, COLOR_RGB2GRAY);
	blur(src_gray, src_gray, Size(3, 3));
	double otsu_thresh_val = threshold(src_gray, img, 0, 255, THRESH_BINARY | THRESH_OTSU);
	double high_thresh_val = otsu_thresh_val, lower_thresh_val = otsu_thresh_val * 0.5;
	cout << otsu_thresh_val;
	Canny(src_gray, canny_output, lower_thresh_val, high_thresh_val, 3);
	namedWindow("source_grey_window", WINDOW_AUTOSIZE);
	imshow("source_grey_window", canny_output);
	imwrite("canny_output.jpg", canny_output);
	RNG rng(12345);
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	vector<Moments> mu(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i], false);
	}
	vector<Point2f> mc(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
	}
	for (int i = 0; i < contours.size(); i++)
	{
		printf("Контур № %d: центр масс - x = %.2f y = %.2f; длина - %.2f\n", i, mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00, arcLength(contours[i],true));
	}
	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3); 
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
		circle(drawing, mc[i], 4, color, -1, 5, 0);
	}
	namedWindow("Контуры", WINDOW_AUTOSIZE);
	imshow("Контуры", drawing);
	waitKey(0);
	system("pause");
	return 0;
}
					    
![Снимок экрана 2021-09-21 124340](https://user-images.githubusercontent.com/67784048/134153469-b91063eb-366b-4b97-9368-9d76b3a816da.png)                         
![Снимок экрана 2021-09-21 124328](https://user-images.githubusercontent.com/67784048/134153551-46720206-e4b8-495f-a575-f9983cba3a37.png)
![Снимок экрана 2021-09-21 125815](https://user-images.githubusercontent.com/67784048/134153727-7d84bca7-441f-42e1-9081-6738f92745bc.png)
![Снимок экрана 2021-09-21 124235](https://user-images.githubusercontent.com/67784048/134153757-bd73d18b-4f32-4883-b624-62ca875fbba0.png)
                                   
                    
 
