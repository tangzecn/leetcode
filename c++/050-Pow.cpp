#include<iostream>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        bool negative = (n < 0);
        long long positive_n = abs((long long)n);
        double base = x, ans = 1.0;
        while (positive_n > 0) {
            if ( positive_n&1 ) {
                ans *= base;
            }
            positive_n = positive_n >> 1;
            base *= base;
        }
        if (negative) ans = 1.0 / ans;
        return ans;
    }
};

int main() {
	return 0;
}