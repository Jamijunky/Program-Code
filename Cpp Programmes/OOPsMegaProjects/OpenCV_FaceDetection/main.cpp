#include "FaceDetector.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace std;
using namespace cv;

int main()
{
  FaceDetector detector;
  if (!detector.loadModel("../haarcascades/haarcascade_frontalface_default.xml"))

  {
    cerr << "Error loading model!" << endl;
    return -1;
  }
  VideoCapture cap(0);
  if (!cap.isOpened())
  {
    cerr << "Error opening video stream!" << "\n";
    return -1;
  }
  Mat frame, gray;
  auto start = chrono::steady_clock::now();
  int frameCount = 0;
  while (true)
  {
    cap >> frame;
    if (frame.empty())
    {
      break;
    }

    int ch = frame.channels();
    cout << "Captured frame with " << ch << " channels" << endl;

    try
    {
      if (ch == 3)
      {
        cvtColor(frame, gray, COLOR_BGR2GRAY);
      }
      else if (ch == 4)
      {
        cvtColor(frame, gray, COLOR_BGRA2GRAY);
      }
      else if (ch == 1)
      {
        gray = frame.clone();
      }
      else
      {
        cerr << "Unexpected number of channels: " << ch << endl;
        break;
      }
    }
    catch (const Exception &e)
    {
      cerr << "OpenCV Exception during cvtColor: " << e.what() << endl;
      break;
    }

    auto faces = detector.detectFaces(gray);
    detector.drawDetections(frame, faces);

    frameCount++;
    auto now = chrono::steady_clock::now();
    float elapsed = chrono::duration_cast<chrono::seconds>(now - start).count();
    float fps = (elapsed > 0) ? frameCount / elapsed : 0.0;

    string text = "Faces: " + to_string(faces.size()) + "| FPS: " + to_string(static_cast<int>(fps));
    putText(frame, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 0), 3);
    putText(frame, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 255), 1);

    imshow("Face Detection", frame);

    if (waitKey(1) == 27)
      break;
  }

  cap.release();
  destroyAllWindows();
  return 0;
}