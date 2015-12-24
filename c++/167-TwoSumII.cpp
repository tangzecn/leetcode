#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int j = numbers.size() - 1;
        for (int i=0; i<numbers.size() && i<j; i++) {
            while (i < j && (long long)numbers[i] + numbers[j] > target) j--;
            if (i < j && (long long)numbers[i] + numbers[j] == target) {
                res.push_back(i + 1);
                res.push_back(j + 1);
                return res;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}