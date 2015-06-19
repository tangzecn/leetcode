#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hashSet;
        for (int i=0; i<nums.size(); i++) {
            int j = i - k - 1;
            if (j >= 0) hashSet.erase(nums[j]);
            if (hashSet.find(nums[i]) != hashSet.end()) return true;
            hashSet.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    return 0;
}