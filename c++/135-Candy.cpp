#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        long long ans = 0;
        int n = ratings.size();
        if (n <= 0) return ans;
        
        vector<int> candy(n, 0);
        for (int i=0; i<n; i++) {
            if (i == 0 || ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            } else {
                candy[i] = 1;
            }
        }
        
        for (int i=n-1; i>=0; i--) {
            if (i < n - 1 && ratings[i] > ratings[i + 1]) {
                candy[i] = max(candy[i + 1] + 1, candy[i]);
            }
            ans += (long long)candy[i];
        }
        
        return ans;
    }
};

int main() {
	return 0;
}