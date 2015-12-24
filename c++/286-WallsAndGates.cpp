#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() == 0 || rooms[0].size() == 0) return;
        int n = rooms.size(), m = rooms[0].size();
        queue<pair<int, int> > points;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) 
                if (rooms[i][j] == 0) {
                    points.push(std::make_pair(i, j));
                }
        int step = 0;
        while (!points.empty()) {
            step++;
            for (int i=points.size(); i>0; i--) {
                int x = points.front().first;
                int y = points.front().second;
                points.pop();
                for (int j=0; j<4; j++) {
                    int x1 = x + MOVE_X[j];
                    int y1 = y + MOVE_Y[j];
                    if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) continue;
                    if (rooms[x1][y1] != INF) continue;
                    rooms[x1][y1] = step;
                    points.push(std::make_pair(x1, y1));
                }
            }
        }
    }

private: 
    static const int INF;
    static const vector<int> MOVE_X;
    static const vector<int> MOVE_Y;
};

const int Solution::INF = INT_MAX;
const vector<int> Solution::MOVE_X = {-1, 1, 0, 0};
const vector<int> Solution::MOVE_Y = {0, 0, -1, 1};

int main() {
    return 0;
}