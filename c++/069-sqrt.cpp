#include<iostream>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if (x < 0) return -1;
        if (x == 0) return 0;
        int left = 0, right = x;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (INT_MAX / mid < mid || mid * mid > x) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    }
};

int main() {
	return 0;
}