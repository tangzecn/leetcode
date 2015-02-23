#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int atoi(string str) {
        int len = str.length(), index = 0;
        // skip extra spaces
        while (index < len && str[index] == ' ') {
            index++;
        }
        
        int ans = 0;
        bool positive = true;
        // plus or minus sign
        if (index < len) {
            if (str[index] == '+') {
                index++;
            } else
            if (str[index] == '-') {
                positive = false;
                index++;
            }
        }
        
        while (index < len && str[index] >= '0' && str[index] <= '9') {
            int digit = str[index] - '0';
            if (positive) {
                if (INT_MAX / 10 < ans || (INT_MAX / 10 == ans && INT_MAX % 10 <= digit)) {
                    return INT_MAX;
                }
            } else {
                if (abs(INT_MIN / 10) < ans || 
                    (abs(INT_MIN / 10) == ans && abs(INT_MIN % 10) <= digit)) {
                    return INT_MIN;
                }
            }
            ans = ans * 10 + digit;
            index++;
        }
        return positive ? ans : -ans;
    }
};

int main() {
    return 0;
}
