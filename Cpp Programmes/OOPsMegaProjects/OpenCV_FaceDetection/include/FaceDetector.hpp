#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
using namespace cv;
using namespace std;
class FaceDetector
{
private:
  CascadeClassifier faceCascade;

public:
  bool loadModel(const string &modelPath);
  vector<Rect> detectFaces(const Mat &frame);
  void drawFaces(Mat& frame, const vector<Rect>& faces);
  void drawDetections(Mat& img, const vector<Rect>& faces);

};
