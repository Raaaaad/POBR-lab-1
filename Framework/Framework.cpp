#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

cv::Mat& zadanie2(cv::Mat& I) {
    int intesityTable[] = {0,0,0,0,0,0,0,0};
    CV_Assert(I.depth() != sizeof(uchar));
    switch (I.channels()) {
    case 3:
        cv::Mat_<cv::Vec3b> _I = I;
        float X, Y;
        std::cout << "X: ";
        std::cin >> X;
        std::cout << "Y: ";
        std::cin >> Y;
        for (int i = 0; i < I.rows; ++i)
            for (int j = 0; j < I.cols; ++j) {
                if (j >= i && i <= (I.rows - j)) {
                    int B = ((int)_I(i, j)[0]) * X;
                    int G = ((int)_I(i, j)[1]) * X;
                    int R = ((int)_I(i, j)[2]) * X;
                    if (B > 255) {
                        B = 255;
                    }
                    if (G > 255) {
                        G = 255;
                    }
                    if (R > 255) {
                        R = 255;
                    }
                    _I(i, j)[0] = B;
                    _I(i, j)[1] = G;
                    _I(i, j)[2] = R;
                }
                if (i > j && j < (I.cols - i)) {
                    int R = _I(i, j)[2];
                    int grey = ((int)_I(i, j)[0] + (int)_I(i, j)[1] + R) / 3;
                    int B = R - grey;
                    int G = R - grey;
                    R = R - grey;
                    if (B < 0) {
                        B = 0;
                    }
                    if (G < 0) {
                        G = 0;
                    }
                    if (R < 0) {
                        R = 0;
                    }
                    _I(i, j)[0] = B;
                    _I(i, j)[1] = G;
                    _I(i, j)[2] = R;
                }
                if (i >= j && i >= (I.rows - j)) {
                    int B = ((int)_I(i, j)[0]) + Y;
                    int G = ((int)_I(i, j)[1]) + Y;
                    int R = ((int)_I(i, j)[2]) + Y;
                    if (B > 255) {
                        B = 255;
                    }
                    if (G > 255) {
                        G = 255;
                    }
                    if (R > 255) {
                        R = 255;
                    }
                    if (B < 0) {
                        B = 0;
                    }
                    if (G < 0) {
                        G = 0;
                    }
                    if (R < 0) {
                        R = 0;
                    }
                    _I(i, j)[0] = B;
                    _I(i, j)[1] = G;
                    _I(i, j)[2] = R;
                }
                int B = ((int)_I(i, j)[0]);
                int G = ((int)_I(i, j)[1]);
                int R = ((int)_I(i, j)[2]);
                int pixelIntensity = (B+G+R)/3;
                if (pixelIntensity >= 0 && pixelIntensity < 32) {
                    intesityTable[0]++;
                }
                if (pixelIntensity >= 32 && pixelIntensity < 64) {
                    intesityTable[1]++;
                }
                if (pixelIntensity >= 64 && pixelIntensity < 96) {
                    intesityTable[2]++;
                }
                if (pixelIntensity >= 96 && pixelIntensity < 128) {
                    intesityTable[3]++;
                }
                if (pixelIntensity >= 128 && pixelIntensity < 160) {
                    intesityTable[4]++;
                }
                if (pixelIntensity >= 160 && pixelIntensity < 192) {
                    intesityTable[5]++;
                }
                if (pixelIntensity >= 192 && pixelIntensity < 224) {
                    intesityTable[6]++;
                }
                if (pixelIntensity >= 224) {
                    intesityTable[7]++;
                }
            }
        std::cout << "Pikseli o jasnosci 0-31 jest " << intesityTable[0] << std::endl;
        std::cout << "Pikseli o jasnosci 32-63 jest " << intesityTable[1] << std::endl;
        std::cout << "Pikseli o jasnosci 64-95 jest " << intesityTable[2] << std::endl;
        std::cout << "Pikseli o jasnosci 96-127 jest " << intesityTable[3] << std::endl;
        std::cout << "Pikseli o jasnosci 128-159 jest " << intesityTable[4] << std::endl;
        std::cout << "Pikseli o jasnosci 160-191 jest " << intesityTable[5] << std::endl;
        std::cout << "Pikseli o jasnosci 192-223 jest " << intesityTable[6] << std::endl;
        std::cout << "Pikseli o jasnosci 224-255 jest " << intesityTable[7] << std::endl;
        std::cout << "Suma pikseli " << intesityTable[0] + intesityTable[1] + intesityTable[2] + intesityTable[3] +
            intesityTable[4] + intesityTable[5] + intesityTable[6] + intesityTable[7] << std::endl;
        I = _I;
        break;
    }
    return I;
}


int main(int, char *[]) {
    std::cout << "Start ..." << std::endl;
    cv::Mat image = cv::imread("Lena.png");
    zadanie2(image);
    cv::imshow("Lena",image);
    cv::waitKey(-1);
    return 0;
}
