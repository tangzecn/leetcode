#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0, index = -1;
        for (int i=0; i<s.length(); i++) {
            int len = findPalindrome(i, i, s);
            if (len > maxLen) {
                maxLen = len;
                index = i - len / 2;
            }
            len = findPalindrome(i, i + 1, s);
            if (len > maxLen) {
                maxLen = len;
                index = i - len / 2 + 1;
            }
        }    
        return s.substr(index, maxLen);
    }
    
    int findPalindrome(int left, int right, const string &s) {
        int len = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            len += (left == right) ? 1 : 2;
            left--;
            right++;
        }
        return len;
    }
};

int main() {
	return 0;
}