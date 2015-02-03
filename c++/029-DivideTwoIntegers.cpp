#include<iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        
        unsigned int remain = dividend >= 0 ? dividend : -dividend; 
        unsigned int absDivisor = divisor >= 0 ? divisor : -divisor;
        unsigned int ans = 0, base = 1;
        while (remain >= absDivisor && remain - absDivisor >= absDivisor) {
            base = base << 1;
            absDivisor = absDivisor << 1;
        }
        while (absDivisor > 0) {
            if (remain >= absDivisor) {
                remain -= absDivisor;
                ans += base;
            }
            base = base >> 1;
            absDivisor = absDivisor >> 1;
        }
        if ((dividend < 0) ^ (divisor < 0)) {
            return -ans;
        } else {
            return (ans > (unsigned int)INT_MAX) ? INT_MAX : ans;
        }
    }
};

int main() {
	return 0;
}