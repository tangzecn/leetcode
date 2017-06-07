#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> count;
        for (int i=0; i<nums.size(); i++) {
            count[nums[i]]++;
        }
        int res = 0;
        for (auto iter = count.begin(); iter != count.end(); iter++) {
            auto find_iter = count.find(iter->first + 1);
            if (find_iter != count.end()) {
                res = max(res, iter->second + find_iter->second);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
