#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int s = 0;
        for (int i=0; i<nums.size(); i++) {
            s ^= nums[i];
        }
        
        int diff = 1;
        while ((s & diff) == 0) {
            diff <<= 1;
        }
        
        vector<int> res(2, 0);
        for (int i=0; i<nums.size(); i++) {
            if ((nums[i] & diff) == 0) {
                res[0] ^= nums[i];
            } else {
                res[1] ^= nums[i];
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
