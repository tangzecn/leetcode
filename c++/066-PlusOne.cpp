#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> ans(digits);
        int index = digits.size() - 1;
        while (index >= 0 && ans[index] >= 9) {
            ans[index] -= 9;
            index--;
        }
        if (index >= 0) {
            ans[index]++;
        } else {
            ans.insert(ans.begin(), 1);
        }
        return ans;
    }
};

int main() {
	return 0;
}