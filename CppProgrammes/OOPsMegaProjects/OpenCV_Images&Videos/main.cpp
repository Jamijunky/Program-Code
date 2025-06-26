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
    void createBlankImage(int height, int width)
    {
        int b = 0, g = 255, r = 255;

        namedWindow("Blank Image Creator", WINDOW_AUTOSIZE);
        createTrackbar("Blue", "Blank Image Creator", &b, 255);
        createTrackbar("Green", "Blank Image Creator", &g, 255);
        createTrackbar("Red", "Blank Image Creator", &r, 255);

        Mat image(height, width, CV_8UC3);

        while (true)
        {
            image.setTo(Scalar(b, g, r));
            imshow("Blank Image Creator", image);

            char key = (char)waitKey(30);
            if (key == 27 || key == 'q')
            {
                destroyAllWindows();
                return;
            }
            else if (key == 's')
            {
                string savePath;
                cout << "Enter filename to save the blank image (e.g., blank.jpg): ";
                cin >> savePath;
                imwrite(savePath, image);
                cout << "Saved to " << savePath << "\n";
            }
        }
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
                {
                    break;
                }
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, imagePath);  
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
    // Blur Video
    void blurVideo()
    {
        VideoCapture cap;
        string input;
        cout << "Enter 'w' for webcam or enter video filename (e.g., sample.mp4): ";
        cin >> input;
        if (input == "w" || input == "W")
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
        if (fps <= 0)
            fps = 30;
        cout << "Resolution: " << width << "x" << height << "\n";
        cout << "FPS: " << fps << "\n";
        int kernelSize;
        int blurType = 0;
        cout << "Enter blur kernel size (odd number, e.g., 5, 9, 15): ";
        cin >> kernelSize;
        if (kernelSize % 2 == 0 || kernelSize <= 0)
        {
            cerr << "Error: Kernel size must be a positive odd number\n";
            return;
        }
        namedWindow("Blurred Video", WINDOW_AUTOSIZE);

        createTrackbar("Kernel Size (odd)", "Blurred Video", &kernelSize, 30);
        createTrackbar("Blur Type (0=G,1=M,2=B)", "Blurred Video", &blurType, 2);

        char saveChoice;
        cout << "Do you want to save the output video? (y/n): ";
        cin >> saveChoice;

        VideoWriter writer;
        if (saveChoice == 'y' || saveChoice == 'Y')
        {
            string savePath;
            cout << "Enter filename to save (e.g., blurred_output.avi): ";
            cin >> savePath;

            int fourcc = VideoWriter::fourcc('M', 'J', 'P', 'G');
            writer.open(savePath, fourcc, fps > 0 ? fps : 30.0, Size(width, height));

            if (!writer.isOpened())
            {
                cerr << " ERROR: Could not open video writer.\n";
                return;
            }

            cout << "Saving to " << savePath << "...\n";
        }

        Mat frame, blurred;
        bool paused = false;
        cout << " BLurring video in real-time. Press 'p' to pause, 'r' to resume, or 'esc' to quit.\n";

        while (true)
        {
            if (!paused)
            {
                cap >> frame;
                if (frame.empty())
                    break;

                int kSize = (kernelSize % 2 == 1) ? kernelSize : kernelSize + 1;
                if (kSize < 1)
                    kSize = 1;

                switch (blurType)
                {
                case 0:
                    GaussianBlur(frame, blurred, Size(kSize, kSize), 0);
                    break;
                case 1:
                    medianBlur(frame, blurred, kSize);
                    break;
                case 2:
                    bilateralFilter(frame, blurred, kSize, kSize * 2, kSize / 2);
                    break;
                }

                stringstream info;
                info << "Blur: " << (blurType == 0 ? "Gaussian" : (blurType == 1 ? "Median" : "Bilateral"));
                putText(blurred, info.str(), Point(15, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);
                putText(blurred, "Press 'p' to pause, 'r' to resume, 'esc' to quit", Point(15, height - 15), FONT_HERSHEY_SIMPLEX, 0.6, Scalar(255, 255, 255), 1);

                imshow("Blurred Video", blurred);

                if (writer.isOpened())
                {
                    writer.write(blurred);
                }
            }

            char key = (char)waitKey(25);
            if (key == 27)
                break;
            else if (key == 'p' || key == 'P')
                paused = true;
            else if (key == 'r' || key == 'R')
                paused = false;
        }

        cap.release();
        if (writer.isOpened())
            writer.release();
        destroyAllWindows();
    }
};

int main()
{
    OpenCVProject app;
    cout << "\n=== OpenCV Interactive Toolkit ===\n";
    while (true)
    {
        cout << "\nChoose option:\n1. Create Blank Image\n2. Play Video\n3. Blur Image\n4. Blur Video\n5. Exit\nChoice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            app.createBlankImage(480, 640);
            break;
        case 2:
            app.playVideo();
            break;
        case 3:
            app.blurImage();
            break;
        case 4:
            app.blurVideo();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }
}
