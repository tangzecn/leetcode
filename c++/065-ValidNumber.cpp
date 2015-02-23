#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int len = s.length();
        // remove tail spaces
        while (len > 0 && s[len - 1] == ' ') len--;
        
        // empty string
        if (len == 0) return false;
        
        bool hasNum = false;
        bool hasPoint = false;
        bool hasE = false;
        
        int index = 0;
        // remove head spaces
        while (s[index] == ' ') index++;
        // skip sign
        if (s[index] == '+' || s[index] == '-') {
            index++;
        }
        while (index < len) {
            if (s[index] >= '0' && s[index] <= '9') {
                if (!hasE) {
                    hasNum = true;
                }
                index++;
            } else
            if (s[index] == '.') {
                // '.' can only occur before 'e' and occur once.
                if (hasPoint || hasE) return false;
                hasPoint = true;
                index++;
            } else 
            if (s[index] == 'e' || s[index] == 'E') {
                // 'e' can only occur once
                if (hasE) {
                    return false;
                } else {
                    hasE = true;
                }
                index++;
                if (index < len && (s[index] == '+' || s[index] == '-')) index++;
                // 'e' must follow a number
                if (index >= len || !(s[index] >= '0' && s[index] <= '9')) {
                    return false;
                } else {
                    index++;
                }
            } else return false;
        }
        return hasNum;
    }
};

int main() {
	return 0;
}