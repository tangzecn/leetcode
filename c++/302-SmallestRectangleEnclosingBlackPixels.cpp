#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minArea(vector<vector<char> >& image, int x, int y) {
        int n = image.size(), m = image[0].size();
        int min_x = binarySearch(image, 0, x, m, true, true);
        int max_x = binarySearch(image, x, n - 1, m, false, true);
        int min_y = binarySearch(image, 0, y, n, true, false);
        int max_y = binarySearch(image, y, m - 1, n, false, false);
        return (max_x - min_x + 1) * (max_y - min_y + 1);
    }
    
private:
    int binarySearch(const vector<vector<char> > &image, int low, int high, int n, bool findMin, bool findRow) {
        int left = low, right = high, mid;
        while (left < right) {
            if (findMin) {
                mid = left + ((right - left) >> 1);
            } else {
                mid = left + ((right - left + 1) >> 1);
            }
            int i = 0;
            while (i < n && ((findRow && image[mid][i] == '0') || (!findRow && image[i][mid] == '0'))) i++;
            if (findMin) {
                if (i < n) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if (i < n) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
        }
        return left;
    }
};

int main() {
    return 0;
}
