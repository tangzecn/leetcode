#include<iostream>
using namespace std;

class Solution {
public:
    // DP: f[i] means number of ways paint from post 1 to post i 
    // f[0] = 1, f[1] = k, f[2] = k * k
    // f[i] = f[i - 1] * (k - 1) + f[i - 2] * (k - 1);  (for i >= 3)
    // f[i - 1] * (k - 1) means the last two posts have different color
    // f[i - 2] * (k - 1) means the last two posts have the same color
    int numWays(int n, int k) {
        if (n <= 0 || k <= 0) return 0;
        if (n == 1) return k;
        int f1 = k, f2 = k * k, f3 = 0;
        for (int i=3; i<=n; i++) {
            f3 = f1 * (k - 1) + f2 * (k - 1);
            f1 = f2;
            f2 = f3;
        }
        return f2;
    }
};

int main() {
    return 0;
}