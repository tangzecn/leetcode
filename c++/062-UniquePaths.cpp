#include<iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n <= 0 || m <= 0) return 0;
        long long ans = 1;
        for (int i = 1; i <= n - 1; i++) {
            ans = ans * (m - 1 + i) / i;
        }
        return ans;
    }
};

int main() {
	return 0;
}