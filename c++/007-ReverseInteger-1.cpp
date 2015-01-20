#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long tmp = abs((long long)x);
        long long ans = 0;
        while (tmp > 0) {
            ans = ans * 10 + tmp % 10;
            tmp /= 10;
        }
        
        // According to the test cases, if the result is exceeding the limit of int-32, should return 0.
        if (x >= 0) {
			if (ans > (long long)INT_MAX) ans = 0;
        } else {
            ans = -ans;
			if (ans < (long long)INT_MIN) ans = 0;
        }
        return ans;
    }
};

int main() {
	return 0;
}
