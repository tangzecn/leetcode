#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int base = 1;
        while (x / base >= 10) {
            base *= 10;
        }
        
        int tmp = x;
        while (tmp > 0) {
            int firstDigit = tmp / base;
            int lastDigit = tmp % 10;
            if (firstDigit != lastDigit) return false;
            tmp -= base * firstDigit;
            tmp /= 10;
            base /= 100;
        }
        return true;
    }
};

int main() {
	return 0;
}