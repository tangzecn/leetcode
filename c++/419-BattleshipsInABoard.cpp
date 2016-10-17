#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char> >& board) {
        if (board.size() == 0 || board[0].size() == 0) return 0;
        
        int res = 0;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if ((board[i][j] == 'X') && (i == 0 || board[i - 1][j] == '.') && 
                    (j == 0 || board[i][j - 1] == '.')) {
                    res++;
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
