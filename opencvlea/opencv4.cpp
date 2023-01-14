#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
//a.resize;Zoom In and zoom out and insert 
void funczoom() {
	Mat m1 = imread("E:/programme/cpp/practice/image/photo.jpg");
	Mat m2;
	int h = m1.rows;
	int w = m1.cols;
	//Scale  horizontally and vertically 
	resize(m1, m2, Size(w * 1.5, h * 1.5), 0, 0, INTER_LINEAR);
	imshow("mywin1", m1);
	imshow("mywin2", m2);
	waitKey(0);
}
//b.flip
void funcflip() {
	Mat m1 = imread("E:/programme/cpp/practice/image/photo.jpg");
	Mat m2;
	//180
	//flip(m1, m2, -1);
	// turn upside down
	flip(m1, m2, 0);
	//Flip side to side
	//flip(m1, m2, 1);
	imshow("mywin1", m2);
	waitKey(0);
}
//c.rotate
void funcroa1() {
	Mat m1 = imread("E:/programme/cpp/practice/image/photo.jpg");
	Mat M, m2;
	int w = m1.cols;
	int h = m1.rows;
	//get the RotationMatrix 
	//45: rotation angle
	M = getRotationMatrix2D(Point2f(w / 2, h / 2), 45, 1.0);
	double cos = M.at<double>(0, 0);
	double sin = M.at<double>(0, 1);
	int newW = w * cos+h*sin;
	int newH = w*sin+cos*h;
	//center coordinate
	M.at<double>(0, 2) += abs(newW - w) / 2.0;
	M.at<double>(1, 2) += abs(newH - h) / 2.0;
	//rorate
	//Size(newW, newH):new image'size; M:convertation matrix
	warpAffine(m1, m2, M, Size(newW, newH), INTER_LINEAR, 0, Scalar(255, 2, 3));
	imshow("mywin1", m2);
	waitKey(0);
}
int mainopencv4() {
	funcroa1();
	system("pause");
	return 0;
}