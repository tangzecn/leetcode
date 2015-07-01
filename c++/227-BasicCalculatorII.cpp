#include<iostream>
using namespace std;

class Solution {
public:
    // O(n) time complexity and O(1) space complexity
    int calculate(string s) {
        long long res = 0, firstOperand = 0;
        char op = '+';
        int i = 0;
        while (i < s.length()) {
            if (s[i] == ' ') {
                i++;
            } else
            if (isDigit(s[i])) {
                long long secondOperand = 0;
                while (i < s.length() && isDigit(s[i])) {
                    secondOperand = secondOperand * 10 + s[i] - '0';
                    i++;
                }
                switch (op) {
                    case '+' : firstOperand += secondOperand; break;
                    case '-' : firstOperand -= secondOperand; break;
                    case '*' : firstOperand *= secondOperand; break;
                    case '/' : firstOperand /= secondOperand; break;
                }
            } else {
                if (s[i] == '+' || s[i] == '-') {
                    res += firstOperand;
                    firstOperand = 0;
                }
                op = s[i];
                i++;
            }
        }
        return res + firstOperand;
    }
    
    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }
};

int main() {
    return 0;
}
