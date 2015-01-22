#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        if (n <= 0) return 0;
        
        int ans = 0;
        vector<int> position(n);
        vector<bool> mark(n);   
        for (int i=0; i<n; i++) {
            mark[i] = false;
        }
        dfs(0, n, ans, position, mark);
        return ans;
    }
    
    void dfs(const int level, const int n, int &ans, vector<int> &position, vector<bool> &mark) {
        if (level >= n) {
            ans++;
            return;
        }
        for (int i=0; i<n; i++) {
            if (mark[i]) continue;
            bool ok = true;
            for (int j=0; j<level; j++) {
                if (abs(j - level) == abs(position[j] - i)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                position[level] = i; mark[i] = true;
                dfs(level + 1, n, ans, position, mark);
                position[level] = 0; mark[i] = false;
            }
        }
    }
};

int main() {
	return 0;
}