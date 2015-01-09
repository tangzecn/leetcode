#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int newN = 0, i = 0;
        while (i < n) {
            int j = i;
            while (j < n && A[i] == A[j]) {
                j++;
            }
            A[newN] = A[i];
            newN++;
            i = j;
        }
        return newN;
    }
};

int main() {
	return 0;
}