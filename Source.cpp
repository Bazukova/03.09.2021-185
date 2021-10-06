#include "opencv2/highgui/highgui.hpp" // определяет кросс=платформенные функций взаимодействия с оконной системой;
#include "opencv2/imgproc/imgproc.hpp" // определяет основные/традиционные функций цифровой обработки изображений;
// отрисовка кривых и тому подобное
#include <iostream> // iostream - заголовочный файл с классами, функциями и переменными для организации ввода-вывода
#include <stdio.h> //  stdio.h - библиотека, содержащий определения макросов, константы и объявления функций и типов
#include <stdlib.h> // stdlib.h - библиотека, содержит в себе функции, занимающиеся выделением памяти, контролем процесса выполнения программы

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	// задаём высоту и ширину картинки
	int height = 520;
	int width = 840;
	Mat img(height, width, CV_8UC3);  //создаётся матрица(Mat) изображение заданной ширены и высоты с 3-х канальным цветом
	// задаём точку для вывода текста
	Point textOrg(100, img.rows / 2);  //Местоположение
	int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX; //настройка шрифта , FONT_HERSHEY_SIMPLEX - тип шрифта
	double fontScale = 2;  //Его масштаб, размер
	Scalar color(200, 100, 50); //цвет текста
	putText(img, "OpenCV Step By", textOrg, fontFace, fontScale, color); // создаем окно; создаёт окно, в которое мы будем выводить наше изображение; первый параметр-название окна;
	// второй - его размер, 0 - даёт возможность изменить размер окна во время выполнения программы, но обычно указывается флаг CV_WINDOW_AUTOSIZE, который указывает, что окно
	// Будет ровно тех же параметров, что и загружаемое в него изображении.
	//namedWindow("Hello World", 0);
	// показываем картинку в созданном окне
	//-эта функция собственно и отображает изображение в окне;
	//первый параметр- название окна для вывода картинки
	//второй параметр- изображение для вывода
	imshow("Hello World", img); //открывает окно
	// ждём нажатия клавиши
	//-эта функция останавливаем программу и ожидает нажатия клавииши заданное 
	// число миллисекунд и продолжает программу, если ничего не нажато
	// Если же, как в нашем случае, параметр функции равен нулю, тогда программа 
	// Ожидает нажатия клавиши и только потом продолжает работу.
	waitKey(0);
	// освобождаем ресурсы
	system("pause");
	return 0;
}
