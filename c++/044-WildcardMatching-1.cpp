#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

class Solution {
public:
    // DP, O(NM)
    bool isMatch(const char *s, const char *p) {
        if (s == NULL || p == NULL) return false;
        
        int lens = strlen(s), lenp = strlen(p);
        
        // for special data, cheating here
        int count = 0;
        for (int i=0; i<lenp; i++) {
            if (p[i] != '*') count++;
        }
        if (count > lens) return false;
        
        vector<vector<bool> > f(2, vector<bool>(lens + 1, false));
        // f[0][0] = true
        f[0][0] = true;
        for (int i=1; i<=lens; i++) {
            // f[0][i] = false
            f[0][i] = false;
        }
        for (int i=1; i<=lenp; i++) {
            // f[i][0] = f[i - 1][0] or false
            f[1][0] = (p[i - 1] == '*') ? f[0][0] : false;
            for (int j=1; j<=lens; j++) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                    // f[i][j] = f[i - 1][j - 1]
                    f[1][j] = f[0][j - 1]; 
                } else
                if (p[i - 1] == '*') {
                    // f[i][j] = f[i - 1][j] || f[i][j - 1]
                    f[1][j] = f[0][j] || f[1][j - 1];
                } else {
                    // f[i][j] = false
                    f[1][j] = false;
                }
            }
            for (int j=0; j<=lens; j++)
                f[0][j] = f[1][j];
        }
        return f[0][lens];
    }
};

int main() {
	return 0;
}
