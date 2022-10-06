#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;


int main(int ac, char** av)
{
	// Detection 하기 위해 필요한 데이터
	int corner = 0; // 모서리의 개수.


	// 이미지 받아옴
	Mat img[4];
	img[0] = imread("1.png", 1);
	img[1] = imread("2.png", 1);
	img[2] = imread("3.png", 1);
	img[3] = imread("4.png", 1);

	// 받아온 이미지를 Detection 하는 알고리즘 작성


	uchar* img_data[4];
	img_data[0] = img[0].data;
	img_data[1] = img[1].data;
	img_data[2] = img[2].data;
	img_data[3] = img[3].data;


	// 4개의 이미지, 너비, 높이, 색의 정보를 담은 배열
	int**** arr = new int*** [4];


	for (int n = 0; n < 4; n++) {
		// Initializing.
		arr[n] = new int** [img[n].rows];
		for (int i = 0; i < img[n].rows; i++) {
			arr[n][i] = new int* [img[n].cols];
		}
		// get color information
		for (int row = 0; row < img[n].rows; row++)
		{
			for (int col = 0; col < img[n].cols; col++)
			{
				arr[n][row][col] = new int[3];

				uchar b = img_data[n][row * img[n].cols * 3 + col * 3];
				uchar g = img_data[n][row * img[n].cols * 3 + col * 3 + 1];
				uchar r = img_data[n][row * img[n].cols * 3 + col * 3 + 2];
				
				arr[n][row][col][0] = (int)r;
				arr[n][row][col][1] = (int)g;
				arr[n][row][col][2] = (int)b;
				printf("\t (%d, %d, %d)", r, g, b);
			}
			cout << "\n" << endl;
		}
	}

	for (int n = 0; n < 4; n++) {
		for (int row = 0; row < img[n].rows; row++) {
			for (int col = 0; col < img[n].cols; col++) {

			}
		}
	}
	

	// 결과 출력함

	// 이미지 출력함 <- 없어도 될듯

	imshow("img1", img[0]);
	imshow("img2", img[1]);
	imshow("img3", img[2]);
	imshow("img4", img[3]);

	waitKey(0);
	return 0;
}