#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > f(m + 1, vector<int>(n + 1, -1));
        f[0][0] = 0;
        for (int i = 0; i < strs.size(); i++) {
            int zeros = 0, ones = 0;
            for (int j = 0; j < strs[i].length(); j++) {
                if (strs[i][j] == '0') {
                    zeros++; 
                } else {
                    ones++;
                }
            }
            for (int j = m ; j >= zeros; j--) {
                for (int k = n; k >= ones; k--) {
                    if (f[j - zeros][k - ones] > -1) {
                        f[j][k] = max(f[j][k], f[j - zeros][k - ones] + 1);
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                res = max(res, f[i][j]);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
