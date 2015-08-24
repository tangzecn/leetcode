#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = 0, n = nums.size();
        for (int i=0; i<n; i++) {
            sum += (long long)nums[i];
        }
        return n * (n + 1) / 2 - sum;
    }
};

int main() {
    return 0;
}
