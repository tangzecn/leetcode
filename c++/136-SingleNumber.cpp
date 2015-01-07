#include<iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ans = 0;
        for (int i=0; i<n; i++) {
            ans = ans ^ A[i];
        }
        return ans;
    }
};

int main() {
	return 0;
}