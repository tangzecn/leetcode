#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> candidates;
        int start, end = 0;
        while (end < nums.size()) {
            while (!candidates.empty() && nums[end] >= nums[candidates.back()]) {
                candidates.pop_back();
            }
            candidates.push_back(end);
            
            start = end - k + 1;
            if (start >= 0) {
                if (candidates.front() < start) {
                    candidates.pop_front();
                }
                res.push_back(nums[candidates.front()]);
            }
            
            end++;
        }
        
        return res;
    }
};

int main() {
    return 0;
}
