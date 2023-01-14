#include<opencv2/opencv.hpp>
#include<string>
#include<iostream>
using namespace std;
using namespace cv;
//a.get the image's histlgram 
void funchisto1() {
	Mat m1 = imread("E:/programme/cpp/practice/image/1.jpg");
	vector<Mat> v1;
	split(m1, v1);
	const int bins[1] = { 256 };
	const int channels[1] = { 0 };
	float hranges[2] = { 0,255 };
	const float* rangs[1] = { hranges };
	Mat b_histo;
	//1.one dimension
	calcHist(&v1[0], 1, 0, Mat(), b_histo, 1, bins, rangs);
	//cout<<b_histo<<endl;
	//cout << b_histo.at<float>(1,0)<<endl;
	//2.two dimension
	Mat m2;
	cvtColor(m1, m2, COLOR_BGR2HSV);
	const int bins2[2] = { 30,32 };
	//numbers of channels
	const int channels2[2] = { 0,1 };
	float hrangse2[2] = { 0,180 };
	float sranges2[2] = { 0,255 };
	const float* rangs2[2] = { hrangse2,sranges2 };
	int hs_channels[2] = { 0,1 };
	Mat hs_histo;
	calcHist(&m2, 1, hs_channels, Mat(), hs_histo, 2, bins2, rangs2);
	//cout << hs_histo << endl;
	namedWindow("mywin2", WINDOW_FREERATIO);
	imshow("mywin2", hs_histo);
	waitKey(0);
}
//b.histogram equalization
void funcequ1() {
	Mat m1 = imread("E:/programme/cpp/practice/image/1.jpg");
	Mat m2;
	cvtColor(m1, m2, COLOR_BGR2GRAY);
	Mat m3;
	//just support single channel
	equalizeHist(m2, m3);
	imshow("mywin2", m3);
	waitKey(0);
}
//c.Image convolution
int funcCon() {
	Mat m1 = imread("E:/programme/cpp/practice/image/1.jpg");
	Mat m2;
	//1.blur:Mean convolution kernel(Same coefficient)
	//Size(5, 5):size of convolution kernel;Point(-1,-1) :default output
	blur(m1, m2, Size(5, 5), Point(-1. - 1));
	imshow("mywin1", m2);
	waitKey(0);
}
//2.Gaussian Blur,not mean convolution kernel;consider weight
void funcGau1() {
	Mat m1 = imread("E:/programme/cpp/practice/image/1.jpg");
	Mat m2;
	//10:x parameter 5:y parameter
	GaussianBlur(m1, m2, Size(0, 0), 10, 5);
}
//3.bilateral convolution kernel (decided by bgr difference and coordinate )
void funcbila() {
	Mat m1 = imread("E:/programme/cpp/practice/image/photo.jpg");
	imshow("mywin1", m1);
	Mat m2;
	//200:sigmaColor; 10:sigmaSpace
	bilateralFilter(m1, m2, 0, 150, 4);
	imshow("mywin2", m2);
	waitKey(0);
}
int main() {
	//funchisto1();
	//funcequ1();
	//funcCon();
	funcbila();
	cout << "rap"<<endl;
	system("pause");
	return 0;
}