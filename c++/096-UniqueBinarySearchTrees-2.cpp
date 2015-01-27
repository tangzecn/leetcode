#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n < 0) return 0;
        long long ans = 1;
        for (int i=1; i<=n; i++) {
            ans = ans * (n + i) / i;
        }
        ans = ans / (n + 1);
        return ans;
    }
};

int main() {
	return 0;
}