#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    static const int n = 9;
    static const int m = 3;
    
    void solveSudoku(vector<vector<char> > &board) {
        bool lineMark[n][n], columnMark[n][n], subboardMark[m][m][n];
        for (int i=0; i<n; i++) 
            for (int j=0; j<n; j++) {
                lineMark[i][j] = false;
                columnMark[i][j] = false;
            }
        for (int i=0; i<m; i++) 
            for (int j=0; j<m; j++) 
                for (int k=0; k<n; k++) {
                    subboardMark[i][j][k] = false;
                }
        
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (board[i][j] != '.') {
                    // should not happen
                    if (!validMark(lineMark, columnMark, subboardMark, i, j, board[i][j])) return;
                    setMark(lineMark, columnMark, subboardMark, i, j, board[i][j]);
                }
        dfs(0, board, lineMark, columnMark, subboardMark);
    }
    
    bool dfs(int index, vector<vector<char> > &board, bool lineMark[n][n], bool columnMark[n][n], bool subboardMark[m][m][n]) {
        if (index >= n * n) {
            return true;
        }
        int i = index / n, j = index % n;
        if (board[i][j] != '.') {
            return dfs(index + 1, board, lineMark, columnMark, subboardMark);
        } else {
            for (char num = '1'; num<='9'; num++) {
                if (validMark(lineMark, columnMark, subboardMark, i, j, num)) {
                    board[i][j] = num;
                    setMark(lineMark, columnMark, subboardMark, i, j, num);
                    if (dfs(index + 1, board, lineMark, columnMark, subboardMark)) return true;
                    board[i][j] = '.';
                    clearMark(lineMark, columnMark, subboardMark, i, j, num);
                }
            }
        }
        return false;
    }
    
    void setMark(bool lineMark[n][n], bool columnMark[n][n], bool subboardMark[m][m][n], int i, int j, char num) {
        num -= '1';
        lineMark[i][num] = true;
        columnMark[j][num] = true;
        subboardMark[i / m][j / m][num] = true;
    }
    
    void clearMark(bool lineMark[n][n], bool columnMark[n][n], bool subboardMark[m][m][n], int i, int j, char num) {
        num -= '1';
        lineMark[i][num] = false;
        columnMark[j][num] = false;
        subboardMark[i / m][j / m][num] = false;
    }    
    
    bool validMark(bool lineMark[n][n], bool columnMark[n][n], bool subboardMark[m][m][n], int i, int j, char num) {
        num -= '1';
        return !lineMark[i][num] && !columnMark[j][num] && !subboardMark[i / m][j / m][num];
    }
};

int main() {
	return 0;
}