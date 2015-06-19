#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) return false;
        unordered_map<int, int> hashMap;
        for (int i=0; i<nums.size(); i++) {
            int j = i - k - 1;
            if (j >= 0) hashMap.erase(nums[j] / (t + 1));
            int bucketNum = nums[i] / (t + 1);
            if (check(hashMap, bucketNum - 1, nums[i], t) || check(hashMap, bucketNum, nums[i], t) ||
                check(hashMap, bucketNum + 1, nums[i], t)) return true;
            hashMap[nums[i] / (t + 1)] = nums[i];
        }
        return false;
    }
    
    bool check(unordered_map<int, int> &hashMap, int bucketNum, int num, int t) {
        unordered_map<int, int>::iterator iter = hashMap.find(bucketNum);
        if (iter == hashMap.end()) return false;
        long long x = iter->second;
        long long y = num;
        return abs(x - y) <= (long long)t;
    }
};

int main() {
  return 0;
}
