#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int newN = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && A[j] == A[i]) {
                if (j - i + 1 <= 2) {
                    A[newN] = A[i];
                    newN++;
                }
                j++;
            }
            i = j;
        }
        return newN;
    }
};

int main() {
	return 0;
}