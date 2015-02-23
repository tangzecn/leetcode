#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.size() < 2 || k < 0) return 0;
        
        int n = prices.size();
        if (k >= n / 2) {
            long long ans = 0;
            for (int i=1; i<n; i++) {
                long long diff = (long long)prices[i] - prices[i - 1];
                if (diff > 0) {
                    ans += diff;
                }
            }
            return (int)ans;
        }
        
        vector<vector<long long> > f(2, vector<long long>(k + 1, 0));
        vector<vector<long long> > g(2, vector<long long>(k + 1, 0));
        long long diff = (long long)prices[1] - prices[0];
        for (int j=0; j<=k; j++) {
            f[0][j] = 0;
            g[0][j] = (j > 0) ? diff : LLONG_MIN;
        }
        for (int i=1; i<n-1; i++) {
            diff = (long long)prices[i + 1] - prices[i];
            f[1][0] = 0;
            g[1][0] = LLONG_MIN;
            for (int j=1; j<=k; j++) {
                // f[i][j] = max{ f[i - 1][j], g[i - 1][j], f[i][j - 1]}
                f[1][j] = max(max(f[0][j], g[0][j]), f[1][j -1]);
                
                // g[i][j] = max{ g[i - 1][j] + diff[i], g[i][j - 1], f[i - 1][j - 1] + diff[i] }
                g[1][j] = max(max(g[0][j] + diff, g[1][j - 1]), f[0][j - 1] + diff);
            }
            for (int j=0; j<=k; j++) {
                f[0][j] = f[1][j];
                g[0][j] = g[1][j];
            }
        }
        return (int)max(g[0][k], f[0][k]);        
    }
};

int main() {
	return 0;
}