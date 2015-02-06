#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int lastNum = 0, currentNum;
        int ans = 0;
        for (int i=0; i<s.length(); i++) {
            currentNum = getNum(s[i]);
            if (i == 0 || currentNum <= lastNum) {
                ans += currentNum;
            } else {
                ans += currentNum - 2 * lastNum;
            }
            lastNum = currentNum;
        }
        return ans;
    }
    
    int getNum(char ch) {
        switch (ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default : return 0;
        }
    }
};

int main() {
	return 0;
}