#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<int> tmp_nums(nums.begin(), nums.end());
        sort(tmp_nums.begin(), tmp_nums.end());
        for (int i=1; i<tmp_nums.size(); i++) {
            if (tmp_nums[i] == tmp_nums[i - 1]) return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
