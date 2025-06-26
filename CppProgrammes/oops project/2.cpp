#include <iostream>
#include <vector>

using namespace std;

void spiralMatrix(vector<vector<int> > &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> spiral;
    int top = 0, left = 0, bottom = m - 1, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) spiral.push_back(matrix[top][i]);
        top++;
        for (int i = top; i <= bottom; i++) spiral.push_back(matrix[i][right]);
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) spiral.push_back(matrix[bottom][i]);
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) spiral.push_back(matrix[i][left]);
            left++;
        }
    }

    cout << "Spiral Pattern: ";
    for (int num : spiral) cout << num << " ";
    cout << endl;

    int product = 1;
    for (size_t i = 2; i < spiral.size(); i += 3)
        product *= spiral[i];

    cout << "Product of every third element: " << product << endl;
}

int main() {
    vector<vector<int> >matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    spiralMatrix(matrix);
    return 0;
}