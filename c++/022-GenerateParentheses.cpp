#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n >= 0) {
            string solution(n * 2, ' ');
            dfs(n, 0, 0, solution, ans);
        }
        return ans;
    }
    
    void dfs(const int &n, int left, int right, string &solution, vector<string> &ans) {
        if (left == n && right == n) {
           ans.push_back(solution);
           return;
        }
        if (left < n) {
            solution[right + left] = '(';
            dfs(n, left + 1, right, solution, ans);
        }
        if (left > right) {
            solution[right + left] = ')';
            dfs(n, left, right + 1, solution, ans);
        }
    }
};

int main() {
    return 0;
}
