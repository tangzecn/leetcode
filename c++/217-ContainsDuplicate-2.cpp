#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;
        for (int i=0; i<nums.size(); i++) {
            if (hashSet.find(nums[i]) != hashSet.end()) return true;
            hashSet.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    return 0;
}
