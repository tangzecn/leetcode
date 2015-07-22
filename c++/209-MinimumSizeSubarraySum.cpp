#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        long long sum = 0;
        int i = 0, res = INT_MAX;
        for (int j=0; j<nums.size(); j++) {
            sum += (long long)nums[j];
            while (i < j && sum - nums[i] >= s) {
                sum -= (long long)nums[i];
                i++;
            }
            if (sum >= s) res = min(j - i + 1, res);
        }    
        if (res == INT_MAX) res = 0;
        return res;
    }
};

int main() {
    return 0;
}
