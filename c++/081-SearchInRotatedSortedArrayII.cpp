#include<iostream>
using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (A[mid] == target) {
                return true;
            } else
            if (A[mid] == A[left] && A[left] == A[right]) {
                right--;
            } else 
            if (A[mid] >= A[left]) {
                if (target < A[mid] && target >= A[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (A[mid] < target && target < A[left]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
	return 0;
}