#include<iostream>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if (x == 0) return 0;
        bool negative = (n < 0);
        double ans = 1.0;
        while (n != 0) {
            if (n & 1) {
                ans = ans * x;
            }
            x *= x;
            n /= 2;
        }
        return negative ? 1.0 / ans : ans;
    }
};

int main() {
	return 0;
}