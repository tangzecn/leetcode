#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        if (T.length() == 0) {
            return "";
        }
        
        unordered_map<char, int> expect;
        unordered_map<char, int> actual;
        
        for (int i=0; i<T.length(); i++) {
            char ch = T[i];
            if (expect.find(ch) == expect.end()) {
                expect[ch] = 1;
                actual[ch] = 0;
            } else {
                expect[ch]++;
            }
        }
        
        string ans = "";
        int i = 0, j = 0, missingCount = T.length();
        while (i < S.length()) {
            while (j < S.length() && missingCount > 0) {
                char ch = S[j];
                if (expect.find(ch) != expect.end()) {
                    actual[ch]++;
                    if (actual[ch] <= expect[ch]) {
                        missingCount--;
                    }
                }
                j++;
            }
            if (missingCount <= 0) {
                if (ans.length() == 0 || j - i < ans.length()) {
                    ans = S.substr(i, j - i);
                }
            }
            
            char ch = S[i];
            if (expect.find(ch) != expect.end()) {
                if (actual[ch] <= expect[ch]) {
                    missingCount++;
                }
                actual[ch]--;
            }
            i++;
        }
        
        return ans;
    }
};

int main() {
	return 0;
}