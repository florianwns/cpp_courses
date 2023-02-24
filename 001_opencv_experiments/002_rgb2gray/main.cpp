//
// Created by Florian Rey on 24/02/2023.
//

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>

using namespace std;
using namespace cv;

#define KEY_UP 0
#define KEY_DOWN 1
#define KEY_LEFT 2
#define KEY_RIGHT 3
#define KEY_Q 113


enum Processing {
    kProcNone,
    kProcCvRGB2GRAY,
    kProcHomeRGB2GRAY,
    KProcLength,
};


Mat rgb2gray(const Mat &bgr) {
    // Accept only BGR matrices
    CV_Assert(bgr.type() == CV_8UC3);

    // Create the grayscale Matrix, fill with zeros
    Mat gray(bgr.rows, bgr.cols, CV_8UC1, Scalar(0));

    // Use iterator to access to pixel values
    auto bgr_it = bgr.begin<Vec3b>(), bgr_end = bgr.end<Vec3b>();
    auto gray_it = gray.begin<uchar>();
    for (; bgr_it != bgr_end; ++bgr_it, ++gray_it) {
        *gray_it = (*bgr_it)[0] * 0.1140 + (*bgr_it)[1] * 0.5870 + (*bgr_it)[2] * 0.2989;
    }
    return gray;
}

int main() {
    VideoCapture cam;
    const int device_id = 0;        // 0 = open default camera

    // specify the VideoCaptureAPIs
    const int api = CAP_ANY;    // 0 = autodetect

    // Open selected camera
    cam.open(device_id, api);

    // Check if camera is opened
    if (!cam.isOpened()) {
        cerr << "Unable to open camera" << endl;
        return -1;
    }


    cout << "Start grabbing" << endl
         << "Press 'q' to terminate" << endl;

    Mat frame;
    int proc = kProcNone;
    while (true) {
        // Grab frame
        cam.read(frame);

        // Check if we succeeded
        if (frame.empty()) {
            cerr << "Blank frame grabbed" << endl;
            break;
        }

        switch (proc) {
            case kProcCvRGB2GRAY:
                cvtColor(frame, frame, COLOR_RGB2GRAY);
                break;
            case kProcHomeRGB2GRAY:
                frame = rgb2gray(frame);
                break;
            default:
                break;
        }

        // Show live and wait for a key with timeout long enough to show images
        imshow("Live", frame);

        // Wait 'q' key to terminate
        switch (waitKey(5)) {
            case KEY_Q:
                return 0;
            case KEY_UP:
            case KEY_LEFT:
            case KEY_RIGHT:
            case KEY_DOWN:
                proc = (proc + 1) % Processing::KProcLength;
                break;
        }
    }

    return 0;
}