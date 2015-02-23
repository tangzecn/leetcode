#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int n = num.size();
        vector<vector<int> > ans;
        if (n < 4) return ans;
        
        sort(num.begin(), num.end());
        for (int i=0; i<n; i++) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            for (int j=i+1; j<n; j++) {
                if (j > i + 1 && num[j] == num[j - 1]) continue;
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long long sum = (long long)num[i] + num[j] + num[k] + num[l];
                    if (sum == (long long)target) {
                        vector<int> solution;
                        solution.push_back(num[i]);
                        solution.push_back(num[j]);
                        solution.push_back(num[k]);
                        solution.push_back(num[l]);
                        ans.push_back(solution);
                        k++;
                    } else
                    if (sum < (long long)target) {
                        k++;
                    } else {
                        l--;
                    }
                    while (k < l && k > j + 1 && num[k] == num[k - 1]) k++;
                    while (k < l && l < n - 1 && num[l] == num[l + 1]) l--;
                }
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}