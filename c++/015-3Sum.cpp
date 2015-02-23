#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int n = num.size();
        vector<vector<int> > ans;
        if (n < 3) return ans;
        
        sort(num.begin(), num.end());
        for (int i=0; i<n; i++) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                long long s = (long long)num[i] + num[j] + num[k];
                if (s == 0) {
                    vector<int> solution;
                    solution.push_back(num[i]);
                    solution.push_back(num[j]);
                    solution.push_back(num[k]);
                    ans.push_back(solution);
                    j++;
                } else
                if (s < 0) {
                    j++;
                } else {
                    k--;
                }
                while (j < k && j > i + 1 && num[j] == num[j - 1]) j++;
                while (j < k && k < n - 1 && num[k] == num[k + 1]) k--;
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}