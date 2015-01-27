#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len1 + len2 != len3) return false;
        
        vector<bool> f(len2 + 1);
        f[0] = true;
        for (int i=1; i<=len2; i++) {
            if (s3[i - 1] == s2[i - 1]) {
                f[i] = f[i - 1];
            } else {
                f[i] = false;
            }
        }
        for (int i=1; i<=len1; i++) {
            for (int j=0; j<=len2; j++) {
                bool newF = false;
                // f[i - 1][j]
                if (s3[i + j - 1] == s1[i - 1]) {
                    newF = newF || f[j];
                }
                // f[i][j - 1]
                if (j > 0 && s3[i + j - 1] == s2[j - 1]) {
                    newF = newF || f[j - 1];
                }
                f[j] = newF;
            }
        }
        return f[len2];
    }
};

int main() {
	return 0;
}