#include "FaceDetector.hpp"
#include <iostream>
using namespace cv;
using namespace std;
bool FaceDetector::loadModel(const string &modePath)
{
    return faceCascade.load(modePath);
}
vector<Rect> FaceDetector::detectFaces(const Mat &frame)
{
    vector<Rect> faces;
    Mat gray, equalized;

    if (frame.channels() == 3)
    {
        cvtColor(frame, gray, COLOR_BGR2GRAY);
    }
    else if (frame.channels() == 4)
    {
        cvtColor(frame, gray, COLOR_BGRA2GRAY);
    }
    else
    {
        gray = frame.clone();
    }

    equalizeHist(gray, equalized);

    faceCascade.detectMultiScale(
        equalized,
        faces,
        1.05,
        6,
        0,
        Size(60, 60));

    vector<Rect> filteredFaces;
    for (auto &face : faces)
    {
        float aspectRatio = (float)face.width / face.height;
        if (aspectRatio > 0.75 && aspectRatio < 1.3)
        {
            filteredFaces.push_back(face);
        }
    }

    return filteredFaces;
}

void FaceDetector::drawFaces(Mat &frame, const vector<Rect> &faces)
{
    for (const auto &face : faces)
    {
        rectangle(frame, face, Scalar(0, 255, 0), 2);
    }
}
void FaceDetector::drawDetections(Mat &img, const vector<Rect> &faces)
{
    for (const auto &face : faces)
    {
        rectangle(img, face, Scalar(0, 255, 0), 2);
    }
}
