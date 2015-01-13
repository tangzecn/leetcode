#include<iostream>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n <= 0) return 0;
        
        long long mins = A[0];
        long long maxs = A[0];
        long long ans = A[0];
        for (int i=1; i<n; i++) {
            long long oldMins = mins;
            long long oldMaxs = maxs;
            mins = min((long long)A[i], min(oldMins * A[i], oldMaxs * A[i]));
            maxs = max((long long)A[i], max(oldMins * A[i], oldMaxs * A[i]));
            ans = max(maxs, ans);
        }
        return ans;
    }
};

int main() {
	return 0;
}