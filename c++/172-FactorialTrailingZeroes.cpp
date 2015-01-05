#include<iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 0) return 0;
        int ans = 0;
        while (n > 0) {
            ans = ans + n / 5;
            n = n / 5;
        }
        return ans;
    }
};

int main() {
	return 0;
}