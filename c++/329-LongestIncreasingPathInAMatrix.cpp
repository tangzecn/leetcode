#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // DP + DFS
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        vector<vector<int> > f(n, vector<int>(m, 0));
        for (int i=0; i<n; i++) 
            for (int j=0; j<m; j++) { 
                f[i][j] = countf(i, j, f, matrix);
                res = max(res, f[i][j]);
            }
        return res;
    }

private:
    int countf(int x, int y, vector<vector<int> > &f, const vector<vector<int>>& matrix) {
        if (f[x][y] > 0) return f[x][y];
        static const vector<int> move_x = {-1, 1, 0, 0};
        static const vector<int> move_y = {0, 0, -1, 1};
        f[x][y] = 1;
        for (int i=0; i<move_x.size(); i++) {
            int x1 = x + move_x[i];
            int y1 = y + move_y[i];
            if (x1 < 0 || x1 >= matrix.size()) continue;
            if (y1 < 0 || y1 >= matrix[0].size()) continue;
            if (matrix[x][y] >= matrix[x1][y1]) continue;
            f[x][y] = max(f[x][y], countf(x1, y1, f, matrix) + 1);
        }
        return f[x][y];
    }
};

int main() {
    return 0;
}
