#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string s1 = preProcess(s);
        vector<int> p(s1.length(), 1);
        int id = -1, mx = -1, startPos = -1, maxLen = 0;
        for (int i=0; i<s1.length(); i++) {
            p[i] = (mx > i) ? min(p[2 * id - i], mx - i) : 1;
            int left = i - p[i], right = i + p[i];
            while (left >= 0 && right < s1.length() && s1[left] == s1[right]) {
                p[i]++;
                left--;
                right++;
            }
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
            if (p[i] - 1 > maxLen) {
                maxLen = p[i] - 1;
                startPos = (i - p[i] + 1) / 2; 
            }
        }
        return s.substr(startPos, maxLen);
    }

    string preProcess(const string &s) {
        string s1(s.length() * 2 + 1, '#');
        for (int i=0; i<s.length(); i++) {
            s1[i * 2 + 1] = s[i];
        }
        return s1;
    }
};

int main() {
	return 0;
}