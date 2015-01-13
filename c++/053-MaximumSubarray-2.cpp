#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n <= 0) return 0;
        
        long long ans = A[0];
        long long maxs = A[0];
        for (int i=1; i<n; i++) {
            maxs = max(maxs + A[i], (long long)A[i]);
            ans = max(ans, maxs);
        }
        return ans;
    }
};

int main() {
	return 0;
}