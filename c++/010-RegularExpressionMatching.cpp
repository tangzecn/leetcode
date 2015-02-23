#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (s == NULL || p == NULL) return false;
        
        int n = strlen(s), m = strlen(p);
        vector<bool> f1(m + 1, false), f2(m + 1, false);
        f2[0] = true;
        for (int j=1; j<=m; j++) {
            if (p[j - 1] == '*') {
                // '*' can't be the first character, j must be greater than 1
                f2[j] = f2[j - 2];
            } else {
                f2[j] = false;
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                f1[j] = f2[j];
            }
            
            // f[i][0] = false
            f2[0] = false;
            for (int j=1; j<=m; j++) {
                if (p[j - 1] == '.') {
                    // f[i][j] = f[i - 1][j - 1]
                    f2[j] = f1[j - 1];
                } else 
                if (p[j - 1] == '*') {
                    // '*' can't be the first character, j must be greater than 1
                    if (p[j - 2] == '.') {
                        // f[i][j] = f[i][j - 2] || f[i - 1][j]
                        f2[j] = f2[j - 2] || f1[j]; 
                    } else {
                        // f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] && f[i - 1][j])
                        f2[j] = f2[j - 2] || ((p[j - 2] == s[i - 1]) && f1[j]);
                    }
                } else {
                    // f[i][j] = (s[i - 1] == p[j - 1]) && f[i - 1][j - 1]
                    f2[j] = (p[j - 1] == s[i - 1]) && f1[j - 1];
                }
            }
        }
        return f2[m];
    }
};

int main() {
	return 0;
}