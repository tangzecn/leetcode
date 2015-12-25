#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i <= num.length() / 2; i++) {
            string num1 = num.substr(0, i);
            if (!validNum(num1)) continue;
            for (int j = 1; j <= (num.length() - i) / 2; j++) {
                string num2 = num.substr(i, j);
                if (!validNum(num2)) continue;
                if (isAdditive(num, i + j, num1, num2)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool isAdditive(const string &num, const int ptr, const string &num1, const string &num2) {
        if (ptr >= num.length()) {
            return true;
        } else {
            string num3 = add(num1, num2);
            if (ptr + num3.length() > num.length() || !validNum(num3)) return false;
            if (num.substr(ptr, num3.length()) != num3) return false;
            return isAdditive(num, ptr + num3.length(), num2, num3);
        }
    }
    
    string add(const string &num1, const string &num2) {
        string res;
        int i = num1.length() - 1, j = num2.length() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int d_i = (i >= 0) ? num1[i--] - '0' : 0;
            int d_j = (j >= 0) ? num2[j--] - '0' : 0;
            int s = d_i + d_j + carry;
            res.push_back('0' + s % 10);
            carry = s / 10;
        }
        if (carry > 0) res.push_back('0' + carry);
        std::reverse(res.begin(), res.end());
        return res;
    }
    
    inline bool validNum(const string &num) {
        return num.length() < 2 || num[0] != '0';
    }
};

int main() {
    return 0;
}