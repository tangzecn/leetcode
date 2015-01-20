#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x <= INT_MIN) return 0;
        int ans = 0, tmp = abs(x);
        while (tmp > 0) {
            int lastDigit = tmp % 10;
            if (ans > (INT_MAX - lastDigit) / 10) return 0;
            ans = ans * 10 + lastDigit;
            tmp /= 10;
        }
        return (x >= 0) ? ans : -ans;
    }
};

int main() {
	return 0;
}
