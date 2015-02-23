#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    static const int n = 9;
    static const int m = 3;
    
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<bool> mark(n, false);
        
        for (int i=0; i<n; i++) {
            clearMark(mark);
            for (int j=0; j<n; j++) {
                if (board[i][j] != '.') {
                    if (mark[board[i][j] - '1']) return false;
                    mark[board[i][j] - '1']  = true;
                }
            }
        }
        
        for (int j=0; j<n; j++) {
            clearMark(mark);
            for (int i=0; i<n; i++) {
                if (board[i][j] != '.') {
                    if (mark[board[i][j] - '1']) return false;
                    mark[board[i][j] - '1']  = true;
                }               
            }
        }
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                clearMark(mark);
                for (int x=i*m; x<(i+1)*m; x++) {
                    for (int y=j*m; y<(j+1)*m; y++) {
                        if (board[x][y] != '.') {
                            if (mark[board[x][y] - '1']) return false;
                            mark[board[x][y] - '1']  = true;
                        }                        
                    }
                }
            }
        }
        
        return true;
    }
    
    void clearMark(vector<bool> &mark) {
        for (int i=0; i<n; i++) {
            mark[i] = false;
        }
    }
};

int main() {
	return 0;
}