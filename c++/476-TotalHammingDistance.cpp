#include<vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            unsigned int mask = 1 << i;
            int zeros = 0, ones = 0;
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] & mask) == 0) {
                    zeros++;
                } else {
                    ones++;
                }
            }
            res += zeros * ones;
        }
        return res;
    }
};

int main() {
    return 0;
}
