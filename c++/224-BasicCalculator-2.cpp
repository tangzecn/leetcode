#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    // Time complexity just depends on the maximal depth of parentheses.
    int calculate(string s) {
        stack<int> signs;
        signs.push(1);
        int sign = 1, ans = 0, i = 0;
        while (i < s.length()) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                ans += num * sign * signs.top();
            } else {
                if (s[i] == '+') sign = 1;
                else if (s[i] == '-') sign = -1;
                else if (s[i] == '(') {
                    signs.push(signs.top() * sign);
                    sign = 1;
                } 
                else if (s[i] == ')') {
                    signs.pop();
                    sign = 1;                    
                }
                i++;
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}
