#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;


int main(int ac, char** av)
{
	// Detection �ϱ� ���� �ʿ��� ������
	int corner = 0; // �𼭸��� ����.


	// �̹��� �޾ƿ�

	Mat img1 = imread("1.png", 1);
	Mat img2 = imread("2.png", 1);
	Mat img3 = imread("3.png", 1);
	Mat img4 = imread("4.png", 1);

	// �޾ƿ� �̹����� Detection �ϴ� �˰��� �ۼ�

	// ��� �����

	// �̹��� ����� <- ��� �ɵ�

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);

	waitKey(0);
	return 0;
}