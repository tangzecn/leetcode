#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        long long original = (long long)x;
        long long reversed = 0, tmp = original;
        while (tmp > 0) {
            reversed = reversed * 10 + tmp % 10;
            tmp /= 10;
        }
        return (original == reversed);
    }
};

int main() {
	return 0;
}