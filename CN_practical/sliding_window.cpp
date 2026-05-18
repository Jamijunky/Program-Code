#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int wsize, frames, i = 0;

    cout << "Enter Window Size: ";
    cin >> wsize;

    cout << "Enter Number of Frames to Send: ";
    cin >> frames;

    while (i < frames) {
        cout << "\nSending frames: ";
        
        for (int j = 0; j < wsize && i + j < frames; j++) {
            cout << i + j << " ";
        }

        cout << "\nAcknowledgment received for frame " << i << endl;

        // Move window forward
        i++;
    }

    cout << "\nAll frames successfully transmitted.\n";

    return 0;
}