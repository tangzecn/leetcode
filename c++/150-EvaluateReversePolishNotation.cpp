#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.size() == 0) return 0;
        
        stack<long long> numbers;
        for (int i=0; i<tokens.size(); i++) {
            if (tokens[i].length() > 1 || (tokens[i][0] >= '0' && tokens[i][0] <= '9')) {
                numbers.push((long long)std::stoi(tokens[i]));    
            } else {
                long long y = numbers.top();
                numbers.pop();
                long long x = numbers.top();
                numbers.pop();
                switch (tokens[i][0]) {
                    case '+' :
                        numbers.push(x + y);
                        break;
                    case '-' :
                        numbers.push(x - y);
                        break;
                    case '*' :
                        numbers.push(x * y);
                        break;
                    case '/' :
                        numbers.push(x / y);
                        break;
                };
            } 
        }
        return numbers.top();
    }
};

int main() {
	return 0;
}
