#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        if (n <= 0) return ans;
        vector<int> solution(n);
        vector<bool> mark(n);
        for (int i=0; i<n; i++) {
            mark[i] = false;
        }
        dfs(0, n, solution, mark, ans);
        return ans;
    }
    
    void dfs(const int level, const int n, 
        vector<int> &solution, vector<bool> &mark, vector<vector<string> > &ans) {
        if (level >= n) {
            string line(n, '.');
            vector<string> solutionBoard;
            for (int i=0; i<n; i++) {
                line[solution[i]] = 'Q';
                solutionBoard.push_back(line);
                line[solution[i]] = '.';
            }
            ans.push_back(solutionBoard);
            return;
        }
        for (int i=0; i<n; i++) {
            if (mark[i]) continue;
            bool ok = true;
            for (int j=0; j<level; j++) {
                if ((j + solution[j] == level + i) || (j - solution[j] == level - i)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                mark[i] = true; solution[level] = i;
                dfs(level + 1, n, solution, mark, ans);
                mark[i] = false; solution[level] = 0;
            }
        }
    }
};

int main() {
	return 0;
}