#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        if (len == 0) return 0;
    
        bool ** isPalindrome;
        isPalindrome = new bool*[len];
        for (int i=0; i<len; i++) {
            isPalindrome[i] = new bool[len];
        }
        for (int k=1; k<=len; k++) {
            for (int j=k-1; j<len; j++) {
                int i = j - k + 1;
                if (k == 1) {
                    isPalindrome[i][j] = true;
                } else 
                if (k == 2) {
                    isPalindrome[i][j] = (s[i] == s[j]);
                } else {
                    isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
                }
            }
        }
        
        vector<int> f(len, INT_MAX);
        for (int i=len-1; i>=0; i--) {
            if (isPalindrome[i][len - 1]) {
                f[i] = 1;
            } else {
                for (int k=i+1; k<len; k++) {
                    if (isPalindrome[i][k - 1]) {
                        f[i] = min(f[i], f[k] + 1);
                    }
                }
            }
        }
        
        for (int i=0; i<len; i++) {
            delete[] isPalindrome[i];
        }
        delete[] isPalindrome;
        return f[0] - 1;
    }
};

int main() {
	return 0;
}