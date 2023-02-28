//
// Created by Florian Rey on 24/02/2023.
//

#include "opencv2/core.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>

using namespace std;

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

    // Show live and wait for a key with timeout long enough to show images
    cv::imshow("Live", frame);

    // Wait 'q' key to terminate
    if (cv::waitKey(5)=='q') {
      break;
    }
  }

  return 0;
}