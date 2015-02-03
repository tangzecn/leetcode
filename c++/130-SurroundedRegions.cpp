#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int n = board.size();
        if (n <= 0) return;
        int m = board[0].size();
        if (m <= 0) return;
        
        vector<int> xqueue, yqueue;
        for (int i=0; i<n; i++) {
            if (tryAddNode(board, xqueue, yqueue, i, 0)) {
                bfs(board, xqueue, yqueue);
            }
            if (tryAddNode(board, xqueue, yqueue, i, m - 1)) {
                bfs(board, xqueue, yqueue);
            }
        }
        for (int i=0; i<m; i++) {
            if (tryAddNode(board, xqueue, yqueue, 0, i)) {
                bfs(board, xqueue, yqueue);
            }
            if (tryAddNode(board, xqueue, yqueue, n - 1, i)) {
                bfs(board, xqueue, yqueue);
            }
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else
                if (board[i][j] == 'Y') {
                    board[i][j] ='O';
                }
            }
        }
    }
    
    void bfs(vector<vector<char> > &board, vector<int> &xqueue, vector<int> &yqueue) {
        static const int move_x[4] = {-1, 0, 1, 0};
        static const int move_y[4] = {0, 1, 0, -1};
        
        int head = 0;
        while (head < xqueue.size()) {
            for (int i=0; i<4; i++) {
                int newx = xqueue[head] + move_x[i];
                int newy = yqueue[head] + move_y[i];
                tryAddNode(board, xqueue, yqueue, newx, newy);
            }    
            head++;
        }        
        xqueue.clear(); yqueue.clear();
    }
    
    bool tryAddNode(vector<vector<char> > &board, vector<int> &xqueue, vector<int> &yqueue, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return false;
        if (board[x][y] != 'O') return false;
        board[x][y] = 'Y';
        xqueue.push_back(x);
        yqueue.push_back(y);
        return true;
    }
};

int main() {
	return 0;
}