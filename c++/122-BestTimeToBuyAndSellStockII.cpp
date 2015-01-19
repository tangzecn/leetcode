#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 1) return 0;
        long long ans = 0;
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                ans += (long long)prices[i] - prices[i - 1];
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
