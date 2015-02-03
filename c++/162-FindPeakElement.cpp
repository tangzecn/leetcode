#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int left = 0, right = num.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if ((mid == 0 || num[mid - 1] < num[mid]) && 
                (mid + 1 >= num.size() || num[mid] > num[mid + 1])) {
                return mid;
            } else
            if (mid > 0 && num[mid - 1] > num[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
	return 0;
}