#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;


int main(int ac, char** av)
{
	// Detection 하기 위해 필요한 데이터
	int corner = 0; // 모서리의 개수.


	// 이미지 받아옴

	Mat img1 = imread("1.png", 1);
	Mat img2 = imread("2.png", 1);
	Mat img3 = imread("3.png", 1);
	Mat img4 = imread("4.png", 1);

	// 받아온 이미지를 Detection 하는 알고리즘 작성

	// 결과 출력함

	// 이미지 출력함 <- 없어도 될듯

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);

	waitKey(0);
	return 0;
}