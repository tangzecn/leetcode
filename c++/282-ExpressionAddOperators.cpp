#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        for (int i=1; i<=num.length(); i++) {
            string st = num.substr(0, i);
            if (!validNum(st)) continue;
            long long curr_num = std::stoll(st);
            dfs(num, target, i, curr_num, 0, st, res);
        }
        return res;
    }
    
private:
    inline bool validNum(string st) {
        return st.length() < 2 || st[0] != '0';
    }
    
    // use '+' or '-' to seperate expression, and calculate each sub-express connected by '*'
    // for example: 1 + 2 * 3 - 4 * 5  --->  (1) + (2 * 3) + (-4 * 5) ---> (1) + (6) + (-20)
    // each sub-express or result in one pair of parentheses called a 'value'
    // thus curr_value means the result of current sub-express, tot_value means the sum of 
    // previous values.
    void dfs(const string &num, const long long target, const int ptr, const long long curr_value, 
             const long long tot_value, const string expr, vector<string> &res) {
        if (ptr >= num.length()) {
            if (tot_value + curr_value == target) {
                res.push_back(expr);
            }
        } else {
            for (int i=ptr+1; i<=num.length(); i++) {
                string st = num.substr(ptr, i - ptr);
                if (!validNum(st)) continue;
                long long curr_num = std::stoll(st);
                dfs(num, target, i, curr_num, tot_value + curr_value, expr + "+" + st, res);
                dfs(num, target, i, -curr_num, tot_value + curr_value, expr + "-" + st, res);
                dfs(num, target, i, curr_value * curr_num, tot_value, expr + "*" + st, res);
            }
        }
    }
};

int main() {
    return 0;
}
