#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        
        int n = prices.size();
        vector<long long> maxProfitFromRight(n);
        maxProfitFromRight[n - 1] = 0;
        long long maxPrice = prices[n - 1], maxProfit = 0;
        for (int i=n-2; i>=0; i--) {
            maxProfit = max(maxProfit, maxPrice - (long long)prices[i]);
            maxProfitFromRight[i] = maxProfit;
            maxPrice = max(maxPrice, (long long)prices[i]);
        }
        
        long long minPrice = prices[0], ans = 0;
        maxProfit = 0;
        for (int i=1; i<n; i++) {
            maxProfit = max(maxProfit, prices[i] - (long long)minPrice);
            long long profit = maxProfit;
            if (i + 1 < n) {
                profit += maxProfitFromRight[i + 1];
            }
            ans = max(ans, profit);
            minPrice = min(minPrice, (long long)prices[i]);
        }
        return (int)ans;
    }
};

int main() {
	return 0;
}