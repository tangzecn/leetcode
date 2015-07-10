#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        long long g0 = 0, g1 = 0, g2 = 0;
        long long f0 = 0, f1 = nums[0], f2 = 0;
        long long res = max(g1, f1);
        for (int i=1; i<nums.size(); i++) {
            g2 = max(g0 + nums[i], g1);
            if (i < nums.size() - 1) {
                f2 = max(f0 + nums[i], f1);
            } else {
                f2 = f1;
            }
            g0 = g1; g1 = g2;
            f0 = f1; f1 = f2;
        }
        return max(f1, g1);
    }
};

int main() {
    return 0;
}