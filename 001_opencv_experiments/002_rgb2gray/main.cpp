//
// Created by Florian Rey on 24/02/2023.
//

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>

using namespace std;

#define KEY_UP 0
#define KEY_DOWN 1
#define KEY_LEFT 2
#define KEY_RIGHT 3
#define KEY_Q 113


enum processings {
    PROC_NONE,
    PROC_CV_RGB2GRAY,
    PROC_LENGTH,
};

int main() {
    cv::VideoCapture cam;
    const int device_id = 0;        // 0 = open default camera

    // specify the cv::VideoCaptureAPIs
    const int api = cv::CAP_ANY;    // 0 = autodetect

    // Open selected camera
    cam.open(device_id, api);

    // Check if camera is opened
    if (!cam.isOpened()) {
        cerr << "Unable to open camera" << endl;
        return -1;
    }

    int proc = PROC_NONE;

    // Grab frame
    cv::Mat frame;
    cout << "Start grabbing" << endl
         << "Press 'q' to terminate" << endl;

    while (true) {
        // Wait for a new frame from camera and store it into 'frame'
        cam.read(frame);

        // Check if we succeeded
        if (frame.empty()) {
            cerr << "Blank frame grabbed" << endl;
            break;
        }

        switch (proc) {
            case PROC_CV_RGB2GRAY:
                cv::cvtColor(frame, frame, cv::COLOR_RGB2GRAY);
                break;
            default:
                break;
        }

        // Show live and wait for a key with timeout long enough to show images
        cv::imshow("Live", frame);

        // Wait 'q' key to terminate
        switch (cv::waitKey(5)) {
            case KEY_Q:
                return 0;
            case KEY_UP:
            case KEY_LEFT:
            case KEY_RIGHT:
            case KEY_DOWN:
                proc = (proc + 1) % PROC_LENGTH;
                break;
        }
    }

    return 0;
}