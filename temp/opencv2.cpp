#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
//一.GUI
//a.track bar
int lightness=0;
Mat m1,m2,m3;
void funccall(int val, void* m) {
	//1.way to get value of bar
	// way1,get lightness
	//when the trackbar's value change,the variable lightness also will change
	m2= Scalar(lightness, lightness, lightness);
	//way2,the val is the value of bar
	//2.we can get the parameter via m.
	//*(Mat *)m;
	add(m1, m2, m3);
	imshow("mywin", m3);
}
void funcctra1() {
	m1 = imread("E:/programme/cpp/practice/image/1.jpg");
	namedWindow("mywin", WINDOW_AUTOSIZE);
	m2 = Mat::zeros(m1.size(), m1.type());
	int max_val = 100;
	//bind variable lightness and bar
	//the second parameter is window's name.it means put the bar in window whose name is mywin
	createTrackbar("myBar", "mywin",  &lightness, max_val,funccall,(void *)&m1);
	imshow("mywin",m1);
	waitKey(0);
}
//b.draw geometric figure
void funcgeo() {
	Mat src1 = imread("E:/programme/cpp/practice/image/photo.jpg");
	Mat src = Mat::zeros(src1.size(), src1.type());
	//1.rectangle
	//x,y,w,h
	Rect r(100, 100, 300, 300);
	//LIN_8:anti-aliasing
	//2:weight of line
	rectangle(src, r, Scalar(255, 0, 0), 2, LINE_8);
	//2.ellipse
	RotatedRect rr;
	rr.center = Point(50, 50);
	rr.size = Size(129, 129);
	rr.angle = 0.0;
	ellipse(src, rr, Scalar(0, 255, 255), -1, LINE_8);
	//3.line and circle
	line(src, Point(1, 1), Point(100, 100), Scalar(255, 0, 255), 4, LINE_8);
	//30:r
	circle(src, Point(200, 200), 30, Scalar(0, 255, 0), -1, LINE_8);
	imshow("mywim1", src);
	//4.polygon
	Point p1(100, 100);
	Point p2(300, 100);
	Point p3(100, 50);
	Point p4(100, 240);
	Point p5(200, 100);
	vector<Point> v1;
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);
	//way1 fill
	fillPoly(src, v1, Scalar(2, 3, 255), LINE_8);
	//way2 just draw line
	//true:closed	4:weight of line
	polylines(src, v1,true, Scalar(3, 5, 255), 4, LINE_8);
	//way3
	vector<vector<Point>> vv1;
	vv1.push_back(v1);
	//2:weight of line ,support -1
	//-1 draw all polyfon
	drawContours(src, vv1, -1, Scalar(2, 3, 255), 2);
	//5.merge
	Mat m4;
	//addWeighted(src1,a,src2,b,g,dst): dst(I)=saturate(src1(I)∗a+src2(I)∗b+g)
	addWeighted(src1, 0.7, src, 0.3, 0, m4);
	imshow("mywin2", m4);
	waitKey(0);
}
//c.addWeighted() and contrast / ˈkɒntrɑːst /
//addWeighted(src1,a,src2,b,g,dst): dst(I)=saturate(src1(I)∗a+src2(I)∗b+g)
//we can change the contrast via changing a
void funccall2(int val,void * m) {
	Mat m1 = *(Mat*)m;
	Mat m2=Mat::zeros(m1.size(),m1.type());
	Mat m3;
	float val1 = val / 100.0;
	addWeighted(m1,val1,m2,0,0,m3);
	imshow("mywin", m3);
}
void funcaddwei() {
	m1 = imread("E:/programme/cpp/practice/image/1.jpg");
	namedWindow("mywin", WINDOW_AUTOSIZE);
	int max_contrast = 300;
	int bindval = 1;
	createTrackbar("myBar", "mywin", &bindval, max_contrast, funccall2, (void*)&m1);
	imshow("mywin", m1);
	waitKey(0);
}
//d.event
//1.keyboard
void funccall4() {

}
void funckey1(){
	m1 = imread("E:/programme/cpp/practice/image/1.jpg");
	namedWindow("mywin", WINDOW_AUTOSIZE);
	imshow("mywin", m1);
	while (true)
	{
		int k = waitKey(300);
		if (k != -1) {
			cout << k << endl;
		}
		if (k == 27) {
			//27:esc
			break;
		}
	}
	cout << "end" << endl;
}
//2.mouse
bool isfirstdr = true;
bool startdra = false;
int x11=0;
int y11=0;
void funccal33(int event, int x, int y, int flags, void* m) {
	Mat m1 = *(Mat*)m;
	Mat temp;
	temp = m1.clone();
	Rect rect(x11, y11, abs(x - x11), abs(y - y11));
	if (event == EVENT_LBUTTONDOWN) {
		//judge if draw firstly
		if (isfirstdr == true) {
			x11 = x;
			y11 = y;
			isfirstdr = false;
			startdra = true;
		}
	}
	else if (event == EVENT_MOUSEMOVE) {
		if (startdra) {
			imshow("mywin1", temp);
			rectangle(temp, rect, Scalar(255, 1, 1), 4, LINE_8);
			imshow("mywin1", temp);
		}
	}
	else if (event == EVENT_LBUTTONUP) {
		isfirstdr = true;
		startdra = false;
	}
}
void funcmouse() {
	Mat m1 = imread("E:/programme/cpp/practice/image/1.jpg");
	namedWindow("mywin1");
	imshow("mywin1", m1);
	//bind handler func for mouse envent
	setMouseCallback("mywin1",funccal33,(void *)&m1 );
	waitKey(0);
}
//二.
//a.applyColorMap():filter (change style of image)
void funcapp1() {
	Mat m1 = imread("E:/programme/cpp/practice/image/1.jpg");
	Mat m2;
	applyColorMap(m1, m2, COLORMAP_CIVIDIS);
	imshow("mywin", m2);
	waitKey(0);
}
//三.channels
//a.spilt and merge and mix(exchange)
void funccha1() {
	//1.split channels
	Mat m1 = imread("E:/programme/cpp/practice/image/1.jpg");
	vector<Mat> v1;
	//v1[0]B（GRAY image）  v1[1]G  v1[2]R
	split(m1,v1);
	imshow("mywin1", v1[0]);
	imshow("mywin2", v1[1]);
	//2.merge
	vector<Mat> v2;
	Mat m2 = Mat::zeros(v1[0].size(), v1[0].type());
	Mat m3;
	v2.push_back(m2);
	v2.push_back(v1[1]);
	v2.push_back(m2);
	//merge
	merge(v2, m3);
	imshow("mywin3", m3);

	//3.mix
	Mat m4=Mat::zeros(m1.size(),m1.type());
	int from_to[] = { 0,2,1,1,2,0 };
	//from_to :channel exchange'ruler
	//input:m1,output:m3;  3channels
	mixChannels(m1, m4, from_to, 3);
	imshow("mywin4", m4);
	waitKey(0);
}
int mainope2() {
	//funcctra1();
	//funckey1();
	//funcapp1();
	//funccha1();
	funcmouse();
	system("pause");
	return 0;
}