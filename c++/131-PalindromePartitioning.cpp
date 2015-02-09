#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        int len = s.length();
    
        vector<vector<bool> > isPalindrome(len, vector<bool>(len, false));
        for (int k=1; k<=len; k++) {
            for (int j=k-1; j<len; j++) {
                int i = j - k + 1;
                if (k == 1) {
                    isPalindrome[i][j] = true;
                } else 
                if (k == 2) {
                    isPalindrome[i][j] = (s[i] == s[j]);
                } else {
                    isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
                }
            }
        }

        vector<vector<string> > ans;
        vector<string> solution;
        dfs(0, s, isPalindrome, solution, ans);
        return ans;
    }
    
    void dfs(const int i, const string &s, const vector<vector<bool> > &isPalindrome, 
        vector<string> &solution, vector<vector<string> > &ans) {
        if (i == s.length()) {
            ans.push_back(solution);
            return;
        }        
        for (int k=i+1; k<=s.length(); k++) {
            if (isPalindrome[i][k - 1]) {
                solution.push_back(s.substr(i, k - i));
                dfs(k, s, isPalindrome, solution, ans);
                solution.pop_back();
            }
        }
    }
};

int main() {
	return 0;
}