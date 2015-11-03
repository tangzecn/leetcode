#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> f;
        f.push_back(nums[0]);
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] <= f[0]) {
                f[0] = nums[i];
            } else
            if (nums[i] > f[f.size() - 1]) {
                f.push_back(nums[i]);
            } else {
                int left = 0, right = f.size() - 1;
                while (left < right) {
                    int mid = (left + right + 1) >> 1;
                    if (nums[i] <= f[mid]) {
                        right = mid - 1;
                    } else {
                        left = mid;
                    }
                }
                f[left + 1] = min(f[left + 1], nums[i]);
            }
        }
        return f.size();
    }
};

int main() {
    return 0;
}
