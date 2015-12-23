#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                while (j < k && (long long)nums[i] + nums[j] + nums[k] >= target) {
                    k--;
                }
                res += (k - j);
                j++;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}