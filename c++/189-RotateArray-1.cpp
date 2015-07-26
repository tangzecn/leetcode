#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        if (nums.size() <= 0) return;
        
        k = k % nums.size();
        if (k < 0) k += nums.size();
        if (k == 0) return;
        
        int tot = 0;
        for (int i=0; i<nums.size() && tot<nums.size(); i++) {
            int j = i;
            do {
                j = (j + k) % nums.size();
                swap(nums[i], nums[j]);
                tot++;
            } while (j != i);
        }
    }
};

int main() {
    return 0;
}
