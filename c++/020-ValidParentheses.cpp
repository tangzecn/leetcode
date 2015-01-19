#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> leftParentheses; 
        for (int i=0; i<s.length(); i++) {
            switch (s[i]) {
                case '(' :
                case '[' :
                case '{' :
                    leftParentheses.push(s[i]);
                    break;
                case ')' :
                    if (leftParentheses.empty() || leftParentheses.top() != '(') return false;
                    leftParentheses.pop();
                    break;
                case ']' :
                    if (leftParentheses.empty() || leftParentheses.top() != '[') return false;
                    leftParentheses.pop();
                    break;
                case '}' :
                    if (leftParentheses.empty() || leftParentheses.top() != '{') return false;
                    leftParentheses.pop();
                    break;
                default : 
                    break;
            }
        }
        return leftParentheses.empty();
    }
};

int main() {
	return 0;
}