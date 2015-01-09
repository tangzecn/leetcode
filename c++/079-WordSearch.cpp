#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    static const int move_x[4];
    static const int move_y[4];
    
    bool exist(vector<vector<char> > &board, string word) {
        if (word.length() < 1) return true;
        int n = board.size();
        if (n < 1) return false;
        int m = board[0].size();
        if (m < 1) return false;
        
        bool **visited;
        visited = new bool*[n];
        for (int i=0; i<n; i++) {
            visited[i] = new bool[m];
            for (int j=0; j<m; j++) {
                visited[i][j] = false;
            }
        }
        
        bool ans = false;
        for (int i=0; i<n && !ans; i++) {
            for (int j=0; j<m && !ans; j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (find(i, j, 1, word, board, visited)) {
                        visited[i][j] = false;
                        ans = true;
                    }
                    visited[i][j] = false;
                }
            }    
        }
        
        for (int i=0; i<n; i++) {
            delete[] visited[i];
        }
        delete[] visited;
        return ans;
    }
    
    bool find(
        const int last_x,
        const int last_y,
        const int step,
        const string &word,
        const vector<vector<char> > &board,
        bool** visited) {
        if (step >= word.length()) return true;
        for (int i=0; i<4; i++) {
            int x = last_x + move_x[i];
            int y = last_y + move_y[i];
            if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visited[x][y]) continue;
            if (word[step] != board[x][y]) continue;
            visited[x][y] = true;
            if (find(x, y, step + 1, word, board, visited)) {
                visited[x][y] = false;
                return true;
            };
            visited[x][y] = false;
        }
        return false;
    }
};

const int Solution::move_x[4] = {0, 1, 0, -1};
const int Solution::move_y[4] = {1, 0, -1, 0};

int main() {
	return 0;
}