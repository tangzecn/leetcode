#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // xxx[i] means the maximal profit from day 0 to day i by a given condition
    // sell[i]: day i sell stock
    // buy[i]: day i buy stock
    // rest[i]: day i do nothing
    // keep[i]: day i keep one stock in hand (sell it someday later)
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        
        vector<long long> sell(2, 0), buy(2, 0), rest(2, 0), keep(2, 0);
        sell[0] = LONG_MIN; buy[0] = -prices[0]; rest[0] = 0; keep[0] = LONG_MIN;
        for (int i=1; i<prices.size(); i++) {
            int today = i & 1;
            int yesterday = !(i&1);
            sell[today] = max(buy[yesterday], keep[yesterday]) + prices[i];
            buy[today] = rest[yesterday] - prices[i];
            rest[today] = max(rest[yesterday], sell[yesterday]);
            keep[today] = max(buy[yesterday], keep[yesterday]);
        }
        
        return max(sell[(prices.size() - 1) & 1], rest[(prices.size() - 1) & 1]);
    }
};

int main() {
    return 0;
}
