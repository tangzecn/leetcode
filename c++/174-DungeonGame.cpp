#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int n = dungeon.size();
        if (n <= 0) return -1;
        int m = dungeon[0].size();
        if (m <= 0) return -1;
        
        vector<long long> f(m, 0);
        // f[n - 1][m - 1]
        f[m - 1] = max(1LL, -(long long)dungeon[n - 1][m - 1] + 1);
        for (int j=m-2; j>=0; j--) {
            // f[n - 1][j] depends on f[n - 1][j + 1]
            f[j] = max(1LL, -(long long)dungeon[n - 1][j] + f[j + 1]);
        }
        for (int i=n-2; i>=0; i--) {
            // f[i][m - 1] depends on f[i + 1][m - 1]
            f[m - 1] = max(1LL, -(long long)dungeon[i][m - 1] + f[m - 1]);
            for (int j=m-2; j>=0; j--) {
                // f[i][j] depends on f[i][j + 1] and f[i + 1][j]
                f[j] = max(1LL, min(f[j + 1], f[j]) - (long long)dungeon[i][j]);
            }
        }
        return f[0];
    }
};

int main() {
    return 0;
}
