#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left_remove = 0, right_remove = 0;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(') {
                left_remove++;
            } else if (s[i] == ')') {
                if (left_remove > 0) {
                    left_remove--;
                } else {
                    right_remove++;
                }
            }
        }
        
        unordered_set<string> res;
        string valid_s(s.length() - left_remove - right_remove, ' ');
        dfs(s, 0, valid_s, 0, left_remove, right_remove, 0, res);
        return vector<string>(res.begin(), res.end());
    }

private:
    void dfs(const string &s, const int s_ptr, string &v_s, const int v_s_ptr, const int left_remove, 
             const int right_remove, const int left_unmatch, unordered_set<string> &res) {
        if (s_ptr >= s.length()) {
            if (v_s_ptr == v_s.length()) {
                res.insert(v_s);
            }
        } else if (s[s_ptr] == '(') {
            if (left_remove > 0) {
                dfs(s, s_ptr + 1, v_s, v_s_ptr, left_remove - 1, right_remove, left_unmatch, res);
            }
            if (v_s_ptr < v_s.length()) {
                v_s[v_s_ptr] = '(';
                dfs(s, s_ptr + 1, v_s, v_s_ptr + 1, left_remove, right_remove, left_unmatch + 1, res);
            }
        } else if (s[s_ptr] == ')') {
            if (right_remove > 0) {
                dfs(s, s_ptr + 1, v_s, v_s_ptr, left_remove, right_remove - 1, left_unmatch, res);
            }
            if (v_s_ptr < v_s.length() && left_unmatch > 0) {
                v_s[v_s_ptr] = ')';
                dfs(s, s_ptr + 1, v_s, v_s_ptr + 1, left_remove, right_remove, left_unmatch - 1, res);
            }
        } else if (v_s_ptr < v_s.length()) {
            v_s[v_s_ptr] = s[s_ptr];
            dfs(s, s_ptr + 1, v_s, v_s_ptr + 1, left_remove, right_remove, left_unmatch, res);
        }
    }
};

int main() {
    return 0;
}
