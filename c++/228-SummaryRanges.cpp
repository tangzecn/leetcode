#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0;
        while (i < nums.size()) {
            int start = nums[i], end = nums[i];
            while (i < nums.size() && nums[i] == end) {
                end++;
                i++;
            }
            if (end - start > 1) {
                res.push_back(std::to_string(start).append("->").append(std::to_string(end - 1)));
            } else {
                res.push_back(std::to_string(start));
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
