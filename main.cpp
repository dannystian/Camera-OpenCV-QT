#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Buka kamera default (0)
    VideoCapture cap(0);

    if (!cap.isOpened()) {
        cerr << "Error: Camera cannot open!" << endl;
        return -1;
    }

    cout << "Press Esc to Exit..." << endl;

    Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) {
            cerr << "Error: Empty Frame!" << endl;
            break;
        }

        imshow("OpenCV Camera", frame);

        // Jika tombol ESC ditekan, keluar
        if (waitKey(10) == 27) {
            cout << "Exit Program." << endl;
            break;
        }
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
