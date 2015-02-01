#include<iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i=0; i<n; i++) {
            while (A[i] >= 1 && A[i] <= n && A[A[i] - 1] != A[i]) {
                int tmp = A[A[i] - 1];
                A[A[i] - 1] = A[i];
                A[i] = tmp;
            }
        }   
        for (int i=0; i<n; i++) 
            if (A[i] != i + 1) {
                return i + 1;
            }
        return n + 1;
    }
};

int main() {
	return 0;
}