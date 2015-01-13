#include<iostream>
#include<string>
#include<cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() <= 0) return true;
        
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && !isAlphanumeric(s[i])) {
                i++;    
            }
            while (i < j && !isAlphanumeric(s[j])) {
                j--;
            }
            if (i < j && toupper(s[i]) != toupper(s[j])) return false;
            i++; j--;
        }
        return true;
    }
    
    bool isAlphanumeric(char ch) {
        return (ch >= '0' && ch <= '9') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z');
    }
};

int main() {
	return 0;
}