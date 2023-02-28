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
  kProcCvBgr2Gray,
  kProcCvThreshold,
  kProcHomeBgr2Gray,
  kProcHomeBgr2SortedGray,
  kProcHomeThreshold,
  KProcLength,
};

Mat bgr_2_gray(const Mat& bgr)
{
    // Accept only BGR matrices
    CV_Assert(bgr.type()==CV_8UC3);

    // Create the grayscale Matrix, fill with zeros
    Mat gray(bgr.rows, bgr.cols, CV_8UC1, Scalar(0));

    // Use iterator to access to pixel values
    auto bgr_it = bgr.begin<Vec3b>(), bgr_end = bgr.end<Vec3b>();
    auto gray_it = gray.begin<uchar>();
    for (; bgr_it!=bgr_end; ++bgr_it, ++gray_it) {
        *gray_it = (*bgr_it)[0]*0.1140+(*bgr_it)[1]*0.5870+(*bgr_it)[2]*0.2989;
    }
    return gray;
}

Mat bgr_2_sorted_gray(const Mat& bgr)
{
    Mat gray = bgr_2_gray(bgr);

    // Use iterator to access to pixel values
    auto it = gray.begin<uchar>(), end = gray.end<uchar>();
    sort(it, end, greater<uchar>{});

    return gray;
}

Mat binarize(const Mat& bgr)
{
    Mat gray = bgr_2_gray(bgr);

    // Use iterator to access to pixel values
    auto it = gray.begin<uchar>(), end = gray.end<uchar>();
    for (; it!=end; ++it) {
        *it = *it<128 ? 0 : 255;
    }

    return gray;
}

int main()
{
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

    Mat frame, res;
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
        case kProcCvBgr2Gray:
            cvtColor(frame, res, COLOR_RGB2GRAY);
            break;
        case kProcCvThreshold:
            res = bgr_2_gray(frame);
            adaptiveThreshold(res, res, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 3, 2);
            break;
        case kProcHomeBgr2Gray:
            res = bgr_2_gray(frame);
            break;
        case kProcHomeBgr2SortedGray:
            res = bgr_2_sorted_gray(frame);
            break;
        case kProcHomeThreshold:
            res = binarize(frame);
            break;
        default:
            res = frame;
            break;
        }

        // Show live and wait for a key with timeout long enough to show images
        imshow("Live", res);

        // Wait 'q' key to terminate
        switch (waitKey(5)) {
        case KEY_Q:return 0;
        case KEY_UP:
        case KEY_LEFT:
        case KEY_RIGHT:
        case KEY_DOWN:proc = (proc+1)%Processing::KProcLength;
            break;
        }
    }

    return 0;
}