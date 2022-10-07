#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;


int main(int ac, char** av)
{
	// Detection �ϱ� ���� �ʿ��� ������
	int corner = 0; // �������� ����.


	// �̹��� �޾ƿ�
	Mat img[4];
	img[0] = imread("1.png", 1);
	img[1] = imread("2.png", 1);
	img[2] = imread("3.png", 1);
	img[3] = imread("4.png", 1);

	// �޾ƿ� �̹����� Detection �ϴ� �˰��� �ۼ�


	uchar* img_data[4];
	img_data[0] = img[0].data;
	img_data[1] = img[1].data;
	img_data[2] = img[2].data;
	img_data[3] = img[3].data;


	// 4���� �̹���, �ʺ�, ����, ���� ������ ���� �迭
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
			}
			cout << "\n" << endl;
		}
	}

	for (int n = 0; n < 4; n++) {
		int* width = new int[img[n].rows];
		for (int row = 0; row < img[n].rows; row++) {
			width[row] = 0;
			for (int col = 0; col < img[n].cols; col++) {
				if (arr[n][row][col][0] != 255 || arr[n][row][col][1] != 255 || arr[n][row][col][2] != 255) {
					width[row]++;
				}
			}
		}

		bool _isRectangle = true;
		int start = 0;
		for (int row = 0; row < img[n].rows; row++) {
			if (width[row] != 0) {
				start = row;
				break;
			}
		}
		
		// rectangle detection
		for (int row = start; row < img[n].rows; row++) {
			if (width[row] != 0) {
				if (width[start] - width[row] < -5 || width[start] - width[row] > 5) {
					_isRectangle = false;
					break;
				}
					
			}
			
		}
		if (!_isRectangle) {
			// circle detection
			bool _isCircle = false;
			for (int row = start; row < img[n].rows-1; row++) {
				if (width[row + 1] == 0) {
					break;
				}
				else if (width[row] - width[row + 1] > 0) {
					_isCircle = true;
					break;
				}
					
			}

			if (!_isCircle) {
				// circle detection
				bool _isTriangle = true;
				for (int row = start; row < img[n].rows-1; row++) {
					if (width[row + 1] == 0) {
						break;
					}
					else if (width[row + 1] - width[row] < 0) {
						_isTriangle = false;
						break;
					}
						
				}
				if (_isTriangle) {
					printf("img%d.jpg�� ����� �ﰢ���Դϴ�\n", n+1);
				}
				else {
					printf("���� �߸��Ǿ����ϴ�\n");
				}
			}
			else {
				printf("img%d.jpg�� ����� ���Դϴ�\n", n+1);
			}
		}
		else {
			printf("img%d.jpg�� ����� �簢���Դϴ�\n", n+1);
		}
	}
	

	// ��� �����

	// �̹��� ����� <- ��� �ɵ�

	imshow("img1", img[0]);
	imshow("img2", img[1]);
	imshow("img3", img[2]);
	imshow("img4", img[3]);

	waitKey(0);
	return 0;
}

//if (row - 1 >= 0 && col - 1 >= 0 && row + 1 <= img[n].rows && col + 1 <= img[n].cols) {
//	if (arr[n][row][col][0] == 255 && arr[n][row][col][1] == 255 && arr[n][row][col][2] == 255) {
//
//	}
//	else {
//		if ((arr[n][row - 1][col - 1][0] != 255 && arr[n][row + 1][col + 1][0] != 255)
//			&& (arr[n][row - 1][col - 1][1] != 255 && arr[n][row + 1][col + 1][1] != 255)
//			&& (arr[n][row - 1][col - 1][2] != 255 && arr[n][row + 1][col + 1][2] != 255)) {
//
//		}
//		else if ((arr[n][row][col - 1][0] != 255 && arr[n][row][col + 1][0] != 255)
//			&& (arr[n][row][col - 1][1] != 255 && arr[n][row][col + 1][1] != 255)
//			&& (arr[n][row][col - 1][2] != 255 && arr[n][row][col + 1][2] != 255)) {
//
//		}
//		else if ((arr[n][row + 1][col - 1][0] != 255 && arr[n][row - 1][col + 1][0] != 255)
//			&& (arr[n][row + 1][col - 1][1] != 255 && arr[n][row - 1][col + 1][1] != 255)
//			&& (arr[n][row + 1][col - 1][2] != 255 && arr[n][row - 1][col + 1][2] != 255)) {
//
//		}
//		else if ((arr[n][row - 1][col][0] != 255 && arr[n][row + 1][col][0] != 255)
//			&& (arr[n][row - 1][col][1] != 255 && arr[n][row + 1][col][1] != 255)
//			&& (arr[n][row - 1][col][2] != 255 && arr[n][row + 1][col][2] != 255)) {
//		}
//		else {
//			corner += 1;
//		}
//	}
//}