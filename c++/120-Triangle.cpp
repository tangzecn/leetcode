#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if (n < 1) return 0;
        
        vector<long long> f(n);
        for (int i=0; i<n; i++) 
            f[i] = triangle[n - 1][i];
        for (int i=n-1; i>0; i--) {
            for (int j=0; j<i; j++) {
                f[j] = min(f[j], f[j + 1]) + triangle[i - 1][j]; 
            }
        }
        
        return f[0];
    }
};

int main() {
	return 0;
}