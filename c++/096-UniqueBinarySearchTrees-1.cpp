#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n < 0) return 0;
        vector<int> f(n + 1);
        f[0] = 1; 
        for (int i=1; i<=n; i++) {
            f[i] = 0;
            for (int j=0; j<i; j++) {
                f[i] += f[j] * f[i - 1 - j];
            }
        }
        
        return f[n];
    }
};

int main() {
	return 0;
}