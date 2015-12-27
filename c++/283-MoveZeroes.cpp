#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr_p = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != 0) {
                nums[curr_p] = nums[i];
                curr_p++;
            }
        }
        for (int i=curr_p; i<nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    return 0;
}