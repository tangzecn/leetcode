#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        if (n < 0) return ans;
        ans.push_back(0);
        for (int i=0; i<n; i++) {
            for (int j=ans.size()-1; j>=0; j--) {
                ans.push_back(ans[j] + (1 << i));
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}