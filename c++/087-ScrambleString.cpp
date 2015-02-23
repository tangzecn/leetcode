#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        if (s1.length() == 0) return true;

        int n = s1.length();
        vector<vector<vector<bool> > > f(n + 1, vector<vector<bool> >(n, vector<bool>(n, false)));
        for (int k=1; k<=n; k++) {
            for (int i=0; i<n-k+1; i++) {
                for (int j=0; j<n-k+1; j++) {
                    if (k == 1) {
                        f[k][i][j] = (s1[i] == s2[j]);
                        continue;
                    }
                    for (int k1=1; k1<k; k1++) {
                        int k2 = k - k1;
                        if ((f[k1][i][j] && f[k2][i+k1][j+k1]) ||
                            (f[k1][i][j+k2] && f[k2][i+k1][j])) {
                            f[k][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return f[n][0][0];
    }
};

int main() {
	return 0;
}