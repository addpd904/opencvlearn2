#include<opencv2/opencv.hpp>
#include<string>
#include<iostream>
using namespace std;
using namespace cv;
//a.read video file
void funcvi1() {
	VideoCapture vca("E:/programme/cpp/practice/1.mp4");
	Mat m1;
	while (true)
	{
		vca.read(m1);
		if (m1.empty()) {
			break;
		}
		int k=waitKey(10);
		if (k == 27) {
			break;
		}
		imshow("mywin1", m1);
	}
	vca.release();
}
//b.some parameter
void funcvi3() {
	VideoCapture vca("E:/programme/cpp/practice/1.mp4");
	Mat m1;
	//1.Total number of frames
	int cout = vca.get(CAP_PROP_FRAME_COUNT);
	//2.fps(Frames per second)
	double fps = vca.get(CAP_PROP_FPS);
	//3.vca.get(CAP_PROP_FOURCC):get the coding scheme
	vca.get(CAP_PROP_FOURCC);
	int wid = vca.get(CAP_PROP_FRAME_WIDTH);
	int  hei = vca.get(CAP_PROP_FRAME_HEIGHT);
	vca.release();
}
//c.save video
void funcvideo2() {
	VideoCapture vca("E:/programme/cpp/practice/1.mp4");
	int wid = vca.get(CAP_PROP_FRAME_WIDTH);
	int  hei= vca.get(CAP_PROP_FRAME_HEIGHT);
	//fps(Frames per second)
	double fps=vca.get(CAP_PROP_FPS);
	//vca.get(CAP_PROP_FOURCC):get the coding scheme
	VideoWriter vw1("E:/programme/cpp/practice/test1.mp4",vca.get(CAP_PROP_FOURCC),fps,Size(wid,hei),true);
	Mat m1;
	vca.read(m1);
	while (!m1.empty())
	{
		vw1.write(m1);
		vca.read(m1);
		//cout << '1'<<endl;
	}
	cout << "successfully" << endl;
	vw1.release();
	vca.release();
}
int mainvideo1() {
	//funcvi1();
	funcvideo2();
	system("pause");
	return 0;
}