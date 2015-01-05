#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long origin = abs(x);
        long long ans = 0;
        bool negative = (x < 0);
        while (origin > 0) {
          ans = ans * (long long int)10 + origin % 10;
          origin /= 10;
        }
        
        // According to the test cases, if the result is exceeding the limit of int-32, should return 0.
        if (negative) {
            ans = -ans;
			if (-((long long)1 << 31) > ans) ans = 0;
        } else {
			if (((long long)1 << 31) - 1 < ans) ans = 0;
        }
        return ans;
    }
};

int main() {
	return 0;
}
