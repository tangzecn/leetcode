#include<iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n <= 0) return -1;
        if (A[n - 1] < target) return n;
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (A[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
	return 0;
}