#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, INT_MAX);
        f[0] = 0;
        for (int i=1; i<=amount; i++) {
            for (int j=0; j<coins.size(); j++) {
                if (coins[j] <= i && f[i - coins[j]] != INT_MAX) {
                    f[i] = min(f[i], f[i - coins[j]] + 1);
                }
            }    
        }
        return f[amount] < INT_MAX ? f[amount] : -1;
    }
};

int main() {
    return 0;
}