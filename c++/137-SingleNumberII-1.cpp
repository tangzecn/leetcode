#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        vector<int> count(32, 0);
        for (int i=0; i<n; i++) {
            int s = A[i];
            for (int i=0; i<32; i++) {
                count[i] = (count[i] + (s & 1)) % 3;
                s = s >> 1;
            }
        }
        int ans = 0;
        for (int i=0; i<32; i++) {
            ans = ans | (count[i] << i);
        }
        return ans;
    }
};

int main() {
	return 0;
}