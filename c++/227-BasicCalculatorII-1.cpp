#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    // Shunting-yard algorithm, from infix expression to postfix expression 
    // Support +, -, *, / but not ()
    int calculate(string s) {
        vector<string> postfix;
        getPostfix(postfix, s);
        return calculate(postfix);
    }
    
private:
    void getPostfix(vector<string> &postfix, const string &s) {
        int i = 0;
        stack<char> ops;
        while (i < s.length()) {
            if (s[i] == ' ') {
                i++; 
                continue;
            } else if (isdigit(s[i])) {
                int j = i;
                while (j < s.length() && isdigit(s[j])) j++;
                postfix.push_back(s.substr(i, j - i));
                i = j;
            } else {
                while (!ops.empty() && getPrecedence(ops.top()) >= getPrecedence(s[i])) {
                    postfix.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.push(s[i]);
                i++;
            }
        }
        while (!ops.empty()) {
            postfix.push_back(string(1, ops.top()));
            ops.pop();
        }
    }
    
    long long calculate(const vector<string> &postfix) {
        stack<long long> operands;
        for (int i=0; i<postfix.size(); i++) {
            if (isdigit(postfix[i][0])) {
                operands.push(std::stoll(postfix[i]));
            } else {
                int y = operands.top(); operands.pop();
                int x = operands.top(); operands.pop();
                switch (postfix[i][0]) {
                    case '+' : operands.push(x + y); break;
                    case '-' : operands.push(x - y); break;
                    case '*' : operands.push(x * y); break;
                    case '/' : operands.push(x / y); break;
                }
            }
        }
        return operands.top();
    }
    
    int getPrecedence(char op) {
        switch (op) {
            case '+' :
            case '-' : return 1;
            case '*' :
            case '/' : return 2;
        }
        return -1;
    }
};

int main() {
    return 0;
}
