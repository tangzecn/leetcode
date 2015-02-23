#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        long long ans = LLONG_MAX;
        long long minDiff = LLONG_MAX;
        if (n < 3) return ans;
        
        sort(num.begin(), num.end());
        for (int i=0; i<n; i++) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                long long sum = (long long)num[i] + num[j] + num[k];
                long long diff = abs((long long)target - sum);
                if (diff < minDiff) {
                    minDiff = diff;
                    ans = sum;
                }
                if (sum == (long long)target) {
                    return ans;
                } else
                if (sum < (long long)target) {
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