#include<iostream>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if (x == 0) return 0;
        if (n < 0) x = 1.0 / x;
        double ans = 1.0;
        while (n != 0) {
            if (n & 1) {
                ans *= x;
            }
            x *= x;
            n /= 2;
        }
        return ans;
    }
};

int main() {
	return 0;
}