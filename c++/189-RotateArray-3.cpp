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
        
        int n1 = nums.size() - k, n2 = k;
        std::reverse(nums.begin(), nums.begin() + n1);
        std::reverse(nums.begin() + n1, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};

int main() {
	return 0;
}