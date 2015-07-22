#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    // BFS
    int numIslands(vector<vector<char> > &grid) {
        static const int move_x[4] = {-1, 0, 1, 0};
        static const int move_y[4] = {0, 1, 0, -1};
        
        int ans = 0;
        int n = grid.size();
        if (n == 0) return ans;
        int m = grid[0].size();
        
        queue<int> qx, qy;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    qx.push(i); qy.push(j);
                    while (!qx.empty()) {
                        for (int k=0; k<4; k++) {
                            int x1 = qx.front() + move_x[k];
                            int y1 = qy.front() + move_y[k];
                            if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) continue;
                            if (grid[x1][y1] != '1') continue;
                            grid[x1][y1] = '3';
                            qx.push(x1);
                            qy.push(y1);
                        }
                        qx.pop();
                        qy.pop();
                    }
                }
            }
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == '3') {
                    grid[i][j] = '1';
                }
            }
        }
        
        return ans;
    }
};

int main() {
    return 0;
}
