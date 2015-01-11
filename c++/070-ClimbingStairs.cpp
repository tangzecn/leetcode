#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        
        int f0 = 1, f1 = 1, f2;
        for (int i=2; i<=n; i++) {
            f2 = f0 + f1;
            f0 = f1;
            f1 = f2;
        }
        
        return f1;
    }
};

int main() {
	return 0;
}