#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

class OpenCVProject
{
public:
    OpenCVProject()
    {
        cout << "OpenCV Project initialized\n";
    }

    // Blank  Image
    void createBlankImage(int height, int width, Scalar color)
    {
        Mat image(height, width, CV_8UC3, color);
        imshow("Blank Image", image);
        imwrite("blank.jpg", image);
        waitKey(0);
        destroyAllWindows();
    }
    // Play Video
    void playVideo(const string &path = "")
    {
        VideoCapture cap;
        string input;
        cout << "Enter 'w' for webcam or enter video filename (e.g., sample.mp4): ";
        cin >> input;
        if (input == "w")
        {
            cap.open(0);
        }
        else
        {
            cap.open(input);
        }
        if (!cap.isOpened())
        {
            cerr << "Error: Could not open video source\n";
            return;
        }
        double fps = cap.get(CAP_PROP_FPS);
        int width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
        int height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));
        cout << "Resolution: " << width << "x" << height << "\n";
        cout << "FPS: " << fps << "\n";

        Mat frame;
        bool paused = false;
        cout << "Playing video. Press 'p' to pause, 'r' to resume, or 'esc' to quit.\n";
        while (true)
        {
            if (!paused)
            {
                cap >> frame;
                if (frame.empty())
                    break;
                imshow("Video Player", frame);
            }

            char key = static_cast<char>(waitKey(25));
            if (key == 27)
            {
                break;
            }
            else if (key == 'p' || key == 'P')
                paused = true;
            else if (key == 'r' || key == 'R')
                paused = false;
        }
        cap.release();
        destroyAllWindows();
    }
    // Blur Image
    void blurImage()
    {
        string imagePath;
        cout << "Enter image file path (e.g., sample.jpg): ";
        cin >> imagePath;
        Mat original = imread(imagePath);
        if (original.empty())
        {
            cerr << "Error: Could not open or find the image\n";
            return;
        }
        int kernelSize;
        cout << "Enter blur kernel size (odd number, e.g., 5, 9, 15): ";
        cin >> kernelSize;
        if (kernelSize % 2 == 0 || kernelSize <= 0)
        {
            cerr << "Error: Kernel size must be a positive odd number\n";
            return;
        }
        Mat blurred;
        GaussianBlur(original, blurred, Size(kernelSize, kernelSize), 0);
        Mat combined;
        hconcat(original, blurred, combined);
        imshow("Original Image VS  Blurred Image", combined);
        cout << "Press 's' to save the blurred image or any other key to skip...\n";
        char key = static_cast<char>(waitKey(0));
        if (key == 's' || key == 'S')
        {
            string savePath;
            cout << "Enter filename to save the blurred image (e.g., blurred.jpg): ";
            cin >> savePath;
            imwrite(savePath, blurred);
            cout << "Saved to " << savePath << "\n";
        }
        destroyAllWindows();
    }
};

int main()
{
    OpenCVProject app;
    // app.createBlankImage(480, 640, Scalar(0, 255, 255));
    app.blurImage();
    // app.playVideo();
    return 0;
}