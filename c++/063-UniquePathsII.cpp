#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0) return 0;
        int m = obstacleGrid[0].size();
        if (m <= 0) return 0;
        
        vector<int> f(m);
        f[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;
        for (int i=1; i<m; i++) {
            f[i] = (obstacleGrid[0][i] == 0) ? f[i - 1] : 0;
        }
        for (int i=1; i<n; i++) {
            f[0] = (obstacleGrid[i][0] == 0) ? f[0] : 0;
            for (int j=1; j<m; j++) {
                f[j] = (obstacleGrid[i][j] == 0) ? f[j - 1] + f[j] : 0; 
            }
        }
        
        return f[m - 1];
    }
};

int main() {
	return 0;
}