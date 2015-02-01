#include<iostream>
#include<stack>
#include<utility>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int> > unmatched;
        int ans = 0;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(') {
                unmatched.push(std::make_pair('(', i));
            } else {
                if (!unmatched.empty() && unmatched.top().first == '(') {
                    unmatched.pop();
                    int validLen = 0;
                    if (unmatched.empty()) {
                        validLen = i + 1;
                    } else {
                        validLen = i - unmatched.top().second;
                    }
                    ans = max(ans, validLen);
                } else {
                    unmatched.push(make_pair(')', i));
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
