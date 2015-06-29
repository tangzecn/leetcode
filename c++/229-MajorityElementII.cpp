#include<vector>
#include<iostream>
using namespace std;

class Solution {
private:
    bool check(const vector<int> &nums, const int candidate, const int m) {
        int count = 0;
        for (int i=0; i<nums.size(); i++) {
            count += (nums[i] == candidate);    
        }
        return (m > 0) && (count > nums.size() / (m + 1));
    }
    
public:
    vector<int> majorityElement(vector<int>& nums) {
        // maximal number of candidates
        static const int m = 2;
        
        vector<int> candidate(m, 0);
        vector<int> count(m, 0);
        for (int i=0; i<nums.size(); i++) {
            bool findSame = false;
            int emptyIndex = -1;
            for (int j=0; j<m; j++) {
                if (count[j] == 0) {
                    emptyIndex = j;
                } else 
                if (candidate[j] == nums[i]) {
                    findSame = true;
                    count[j]++;
                    break;
                }
            }
            if (!findSame) {
                if (emptyIndex >= 0) {
                    candidate[emptyIndex] = nums[i];
                    count[emptyIndex] = 1;
                } else {
                    for (int j=0; j<m; j++) 
                        count[j]--;
                }
            }
        }
        
        vector<int> res;
        for (int i=0; i<m; i++) 
            if (count[i] > 0 && check(nums, candidate[i], m)) {
                res.push_back(candidate[i]);
            }
        return res;
    }
};

int main() {
    return 0;
}
