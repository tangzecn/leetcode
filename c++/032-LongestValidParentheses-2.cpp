#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int len = s.length();
        if (len == 0) return 0;
        
        vector<int> f(len);
        f[0] = 0;
        for (int i=1; i<s.length(); i++) {
            int j = (i - 1) - f[i - 1];
            if (j >= 0 && s[j] == '(' && s[i] == ')') {
                if (j > 0) {
                    f[i] = i - j + 1 + f[j - 1];
                } else {
                    f[i] = i - j + 1;
                }
            } else {
                f[i] = 0;
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
};

int main() {
    return 0;
}
