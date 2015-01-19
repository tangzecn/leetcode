#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string solution(digits.size(), ' ');
        dfs(0, digits, solution, ans);
        return ans;
    }
    
    void dfs(const int index, const string &digits, string &solution, vector<string> &ans) {
        static const string chs[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (index >= digits.size()) {
            ans.push_back(solution);
            return;
        }
        int digit = digits[index] - '0';
        for (int i=0; i<chs[digit].size(); i++) {
            solution[index] = chs[digit][i];
            dfs(index + 1, digits, solution, ans);
        }
    }
};

int main() {
	return 0;
}