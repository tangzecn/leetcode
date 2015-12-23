#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        
        int n = grid.size(), m = grid[0].size();
        int building_cnt = 0;
        vector<vector<int> > total_dist(n, vector<int>(m, 0));
        vector<vector<int> > reach_cnt(n, vector<int>(m, 0));
        const vector<int> MOVE_X = {-1, 1, 0, 0};
        const vector<int> MOVE_Y = {0, 0, -1, 1};
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1) {
                    building_cnt++;
                    int step = 0;
                    vector<vector<bool> > visit(n, vector<bool>(m, false));
                    queue<std::pair<int, int> > points;
                    points.push(std::make_pair(i, j));
                    while (!points.empty()) {
                        step++;
                        for (int level_cnt=points.size(); level_cnt>0; level_cnt--) {
                            int x = points.front().first;
                            int y = points.front().second;
                            points.pop();
                            for (int k=0; k<MOVE_X.size(); k++) {
                                int x1 = x + MOVE_X[k];
                                int y1 = y + MOVE_Y[k];
                                if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) continue;
                                if (visit[x1][y1] || grid[x1][y1] != 0) continue;
                                points.push(std::make_pair(x1, y1));
                                visit[x1][y1] = true;
                                total_dist[x1][y1] += step;
                                reach_cnt[x1][y1]++;
                            }
                        }
                    }
                }
            }
        }
        
        int res = INT_MAX;
        for (int i=0; i<n; i++) 
            for (int j=0; j<m; j++) 
                if (reach_cnt[i][j] == building_cnt) {
                    res = min(res, total_dist[i][j]);
                }
        
        return res < INT_MAX ? res : -1;
    }
};

int main() {
    return 0;
}