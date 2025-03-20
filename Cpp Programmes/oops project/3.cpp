#include <iostream>
#include <vector>

using namespace std;

bool isPeakValleyGraph(vector<int> &heights) {
    int n = heights.size();
    if (n < 3) return false;

    for (int i = 1; i < n - 1; i++) {
        if (!((heights[i] > heights[i - 1] && heights[i] > heights[i + 1]) || 
              (heights[i] < heights[i - 1] && heights[i] < heights[i + 1]))) {
            return false;
        }
    }
    return true;
}

int highestPeak(vector<int> &heights) {
    int maxPeak = -1;
    for (size_t i = 1; i < heights.size() - 1; i++) {
        if (heights[i] > heights[i - 1] && heights[i] > heights[i + 1])
            maxPeak = max(maxPeak, heights[i]);
    }
    return maxPeak;
}

int main() {
    vector<int> heights = {5, 7, 4, 6, 3};
    if (isPeakValleyGraph(heights)) {
        cout << "Highest Peak: " << highestPeak(heights) << endl;
    } else {
        cout << "Not a Peak Valley Graph" << endl;
    }
    return 0;
}
