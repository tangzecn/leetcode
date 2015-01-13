#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n <= 0) return 0;
        return getSubArrayMax(A, 0, n - 1);
    }
    
    long long getSubArrayMax(const int A[], int left, int right) {
        if (left > right) return LLONG_MIN;
        int mid = (left + right) >> 1;
        long long sum = 0;
        long long leftMaxs = 0;
        for (int i = mid - 1; i >= left; i--) {
            sum += A[i];
            leftMaxs = max(sum, leftMaxs);
        }
        sum = 0;
        long long rightMaxs = 0;
        for (int i = mid + 1; i<=right; i++) {
            sum += A[i];
            rightMaxs = max(sum, rightMaxs);
        }
        return max(max(leftMaxs + A[mid] + rightMaxs, getSubArrayMax(A, left, mid - 1)), 
            getSubArrayMax(A, mid + 1, right));
    }
};

int main() {
	return 0;
}