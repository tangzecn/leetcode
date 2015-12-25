#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
        int n = board.size(), m = n > 0 ? board[0].size() : 0;
        for (int i=0; i<n; i++) 
            for (int j=0; j<m; j++) {
                int sum = 0;
                for (int k=0; k<MOVE_X.size(); k++) {
                    int x = i + MOVE_X[k];
                    int y = j + MOVE_Y[k];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    sum += (board[x][y] & 1);
                }
                if (board[i][j] & 1) {
                    if (sum == 2 || sum == 3) {
                        board[i][j] |= 2;
                    }
                } else {
                    if (sum == 3) {
                        board[i][j] |= 2;
                    }
                }
            }
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                board[i][j] >>= 1;
    }

private:
    static const vector<int> MOVE_X;
    static const vector<int> MOVE_Y;
};

const vector<int> Solution::MOVE_X = {-1, -1, -1, 0, 0, 1, 1, 1};
const vector<int> Solution::MOVE_Y = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    return 0;
}