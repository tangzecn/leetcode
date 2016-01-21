#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long long, int> sum_map;
        sum_map[0] = -1;
        long long sum = 0;
        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
            long long sub_sum = sum - k;
            auto iter = sum_map.find(sub_sum);
            if (iter != sum_map.end()) {
                res = max(res, i - iter->second);
            }
            if (sum_map.find(sum) == sum_map.end()) {
                sum_map[sum] = i;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
