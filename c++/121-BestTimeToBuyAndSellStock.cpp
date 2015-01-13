#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 1) return 0;
        
        long long minPrice = prices[0];
        long long ans = 0;
        for (int i=1; i<prices.size(); i++) {
            ans = max(ans, (long long)prices[i] - minPrice);
            minPrice = min(minPrice, (long long)prices[i]);
        }
        return ans;
    }
};

int main() {
	return 0;
}