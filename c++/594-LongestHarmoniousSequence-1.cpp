#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int res = 0, pre_num = 0, pre_count = 0, curr_num = 0, curr_count = 0;
        for (int i=0; i<nums.size(); i++) {
            curr_num = nums[i]; curr_count = 1;
            int j = i;
            while (j + 1 < nums.size() && nums[j + 1] == curr_num) {
                j++; curr_count++;
            }
            if (i > 0 && curr_num - pre_num == 1) {
                res = max(res, pre_count + curr_count);
            }
            i = j;
            pre_num = curr_num; pre_count = curr_count;
        }
        return res;
    }
};

int main() {
    return 0;
}
