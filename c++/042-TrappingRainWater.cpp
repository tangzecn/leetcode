#include<iostream>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        long long ans = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            if (A[left] <= A[right]) {
                long long height = A[left];
                while (left < right && A[left] <= height) {
                    ans += (height - A[left]);
                    left++;
                }
            } else {
                long long height = A[right];
                while (left < right && A[right] <= height) {
                    ans += (height - A[right]);
                    right--;
                }
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}