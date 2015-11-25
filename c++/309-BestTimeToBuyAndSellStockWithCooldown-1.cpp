#include<vector>
using namespace std;

class Solution {
public:
    // buy[i] : maximal profit from day 0 to day i, and last operation is buy 
    // sell[i] : maximal profit from day 0 to day i, and last operation is sell
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        
        vector<long long> buy(3, LONG_MIN), sell(3, 0);
        for (int i=0; i<prices.size(); i++) {
            int today = i % 3;
            int yesterday = ((i - 1) + 3) % 3;
            int day_before_yesterday = ((i - 2) + 3) % 3;
            buy[today] = max(buy[yesterday], sell[day_before_yesterday] - prices[i]);
            sell[today] = max(sell[yesterday], buy[yesterday] + prices[i]);
        }
        return sell[(prices.size() - 1) % 3];
    }
};

int main() {
    return 0;
}
