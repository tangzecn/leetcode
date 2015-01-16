#include<iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int newN = 0;
        for (int i=0; i<n; i++) {
            if (A[i] != elem) {
                A[newN] = A[i];
                newN++;
            }
        }
        return newN;
    }
};

int main() {
	return 0;
}