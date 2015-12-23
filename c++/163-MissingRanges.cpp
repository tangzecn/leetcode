#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int ptr = lower;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] < lower || nums[i] > upper) continue;
            if (nums[i] == ptr) {
                ptr++; continue;
            }
            int left = ptr;
            int right = nums[i] - 1;
            addRange(left, right, res);
            ptr = nums[i] + 1;
        }
        if (ptr <= upper) {
            addRange(ptr, upper, res);
        }
        return res;
    }
    
private:
    void addRange(const int left, const int right, vector<string> &res) {
        if (left < right) {
            res.push_back(std::to_string(left) + "->" + std::to_string(right));
        } else {
            res.push_back(std::to_string(left));
        }
    }
};

int main() {
    return 0;
}