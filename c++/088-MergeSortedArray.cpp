#include<iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1, j = n - 1, k = n + m - 1;
        while (i >= 0 || j >= 0) {
            if (j < 0 || (i >= 0 && A[i] >= B[j])) {
                A[k] = A[i];
                k--; i--;
            } else {
                A[k] = B[j];
                k--; j--;
            }
        }
    }
};

int main() {
	return 0;
}