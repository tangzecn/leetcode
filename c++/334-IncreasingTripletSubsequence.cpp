#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // The special case of "finding longest increasing subsequence" 
    // DP for "finding longest increasing subsequence" could be O(N log N)
    // in this case, logN = log3, thus time complexity is O(N)
    bool increasingTriplet(vector<int>& nums) {
        vector<int> min_num;
        for (int i=0; i<nums.size(); i++) {
            if (min_num.size() == 0 || nums[i] > min_num[min_num.size() - 1]) {
                min_num.push_back(nums[i]);
            } else if (nums[i] <= min_num[0]) {
                min_num[0] = nums[i];
            } else {
                for (int j=min_num.size() - 1; j >= 0; j--) {
                    if (nums[i] > min_num[j]) {
                        min_num[j + 1] = nums[i];
                        break;
                    }
                }
            }
            if (min_num.size() >= SEQ_LEN) return true;
        }
        return false;
    }

private:
    const static int SEQ_LEN;
};

const int Solution::SEQ_LEN = 3;

int main() {
    return 0;
}