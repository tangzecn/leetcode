#include<iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int bitPos[2], three = 0;
        for (int i=0; i<n; i++) {
            bitPos[1] |= bitPos[0] & A[i];
            bitPos[0] ^= A[i];
            three = bitPos[0] & bitPos[1];
            bitPos[1] ^= three;
            bitPos[0] ^= three;
        }
        return bitPos[0];
    }
};

int main() {
	return 0;
}