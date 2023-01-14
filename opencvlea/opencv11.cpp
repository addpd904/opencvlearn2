//opencv 451
#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
//a.show image
void funcim1() {
	Mat src = imread("E:/programme/cpp/practice/image/1.jpg");
	//judge if it is empty;
	//src.empty();
	namedWindow("mywindow", WINDOW_FREERATIO);
	//imshow just suport 8bit image
	imshow("mywindow", src);
	//blocking
	waitKey(0);
	destroyAllWindows();
}
//b.color space conversion
void funccsc1() {
	Mat src = imread("E:/programme/cpp/practice/image/1.jpg");
	if (src.empty()) {
		return;
	}
	Mat im1, im2;
	//1.color space conversion
	// RGB to HSV
	//HSV color space;H:0~180;S and V 0~255;H and S represents color;V represents the brightness
	cvtColor(src, im1, COLOR_BGR2HSV);
	//RGB to GRAY ;gray color space
	cvtColor(src, im2, COLOR_BGR2GRAY);
	//save
	imwrite("E:/programme/cpp/practice/image/myimgae1.jpg", im2);
	namedWindow("mywindow2", WINDOW_FREERATIO);
	//imshow just suport 8bit image
	imshow("mywindow2", im1);
	//blocking
	waitKey(0);
	destroyAllWindows();
}
//二.Mat(matrix),all image is mat object
//a.define and assign
void funcmat1() {
	//way1
	Mat m1 = imread("E:/programme/cpp/practice/image/myimgae1.jpg");
	Mat m2;
	//way2
	m1.copyTo(m2);
	//way3
	m2 = m1.clone();
	imshow("mywin", m2);
	waitKey(2000);
	//way4
	//(400,400) means pixel is 400X400;CV_8UC3(8 bit unsigned char) means there are 3 chanels.
	m2 = Mat::zeros(Size(400, 400), CV_8UC3);
	//way 5,return a rgb mat
	m2 = Scalar(0, 0, 255);
	imshow("mywin2", m2);
	waitKey(2000);
}
//b.some parameter
void funcmat2() {
	Mat m1 = Mat::ones(Size(400, 200), CV_8UC2);
	//cols:pixel's amout
	cout << m1.cols << " " << m1.rows << " " << m1.channels() << endl;
	m1.size();
	m1.type();
}
//c.modify pixel
void funcmat3() {
	Mat m1 = imread("E:/programme/cpp/practice/image/myimgae1.jpg");
	int rows = m1.rows;
	//1.way1 vec3b
	//columns:pixel's amout
	int columns = m1.cols;
	int cha = m1.channels();
	cout << cha << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			Vec3b bgr = m1.at<Vec3b>(i, j);
			m1.at<Vec3b>(i, j)[0] = 255 - bgr[0];
			m1.at<Vec3b>(i, j)[1] = 255 - bgr[1];
			m1.at<Vec3b>(i, j)[2] = 255 - bgr[2];
		}
		cout << endl;
	}
	imshow("mywindow3", m1);
	//2.way2
	Mat m2 = imread("E:/programme/cpp/practice/image/myimgae1.jpg");
	int r = m2.rows;
	int c = m2.cols;
	int cha2 = m2.channels();
	for (int i = 0; i < r; i++)
	{
		uchar* ptr = m2.ptr<uchar>(i);
		for (int j = 0; j < c; j++) {
			*ptr++ = 255 - *ptr;
			*ptr++ = 255 - *ptr;
			*ptr++ = 255 - *ptr;
		}
	}
	imshow("mywin4", m2);
}
//三.operation
void funcmat4() {
	//a.arithmetic operation
	Mat m1 = imread("E:/programme/cpp/practice/image/1.jpg");
	m1 += Scalar(50, 50, 50);
	m1 /= Scalar(2, 2, 2);
	Mat m3;
	multiply(m1, Scalar(3, 3, 3), m3);
	divide(m1, Scalar(2, 2, 2), m3);
	//others: subtract(), add()
	imshow("mywin", m1);
	imshow("mywin2", m3);
	waitKey(0);
}
//b.logic operation
void funclog() {
	Mat m1 = Mat::zeros(Size(500, 500), CV_8UC3);
	//create a rectangle;(100,100) is coordinates; (90, 90) is size
	//Scalar(255, 255, 0) is color; -1 means filling color,greater 0 means stroking
	//LINE_8 :anti-aliasing
	rectangle(m1, Rect(100, 100, 90, 90), Scalar(255, 255, 0), -1, LINE_8, 0);
	Mat m2 = Mat::zeros(Size(500, 500), CV_8UC3);
	rectangle(m2, Rect(130, 130, 90, 90), Scalar(0, 255, 0), -1, LINE_8, 0);
	Mat m3;
	//(255, 255, 0) and (0,255,0)->(0,255,0)
	//bitwise_and(m1, m2, m3);
	//bitwise_not(m1, m3);
	//bitwise_or(m1, m2, m3);
	//xor:异或
	bitwise_xor(m1, m2, m3);
	imshow("mywin", m3);
	waitKey(0);
}
int maincv1(int argc, char** argv) {
	//funcim1();
	//funccsc1();
	//funcmat1();
	//funcmat3();
	//funcmat4();
	funclog();
	system("pause");

	return 0;
}