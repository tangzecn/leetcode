#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        if (numbers.size() < 2) return ans;
        
        unordered_map<int, int> num_map;
        const long long MIN_INT = - ((long long)1 << 31);
        const long long MAX_INT = ((long long)1 << 31) - 1;
        for (int i=0; i<numbers.size(); i++) {
            long long another_num = (long long)target - numbers[i];
            if (another_num >= MIN_INT && another_num <= MAX_INT) {
                if (num_map.find(another_num) != num_map.end()) {
                    ans.push_back(num_map[another_num] + 1);
                    ans.push_back(i + 1);
                    return ans;
                }
            }
            num_map[numbers[i]] = i;
        }
        
        return ans;
    }
};

int main() {
    return 0;
}