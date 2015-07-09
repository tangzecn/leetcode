#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;   
        if (n <= 0) return res;
        
        int left = n, right = 0, exp = 0;
        while (left > 0) {
            int lastDigit = left % 10;
            if (lastDigit > 1) {
                res += (left / 10 + 1) * (int)pow(10, exp);
            } else if (lastDigit == 1) {
                res += left / 10 * (int)pow(10, exp) + (right + 1);
            } else {
                res += left / 10 * (int)pow(10, exp);
            }
            
            right = (int)pow(10, exp) * lastDigit + right;
            left /= 10;
            exp++;
        }
        
        return res;
    }
};

int main() {
	return 0;
}