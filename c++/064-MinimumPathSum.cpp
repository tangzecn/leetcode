#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        
        vector<int> f(m);
        f[0] = grid[0][0];
        for (int i=1; i<m; i++)
            f[i] = f[i - 1] + grid[0][i];
        for (int i=1; i<n; i++) {
            f[0] = f[0] + grid[i][0];
            for (int j=1; j<m; j++) {
                f[j] = min(f[j], f[j - 1]) + grid[i][j];
            }
        }
        
        return f[m - 1];
    }
};

int main() {
	return 0;
}