#include<iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((n + m) % 2 == 1) {
            return findNum(A, m, B, n, (n + m + 1) / 2);
        } else {
            return (findNum(A, m, B, n, (n + m) / 2) + findNum(A, m, B, n, (n + m) / 2 + 1)) / 2;
        }
    }
    
    double findNum(const int *a, const int m, const int *b, const int n, const int k) {
        if (m > n) {
            return findNum(b, n, a, m, k);
        } else 
        if (m == 0) {
            return b[k - 1];
        } else
        if (k == 1) {
            return a[0] < b[0] ? a[0] : b[0];
        } else {
            int pa = min(k / 2, m), pb = k - pa;
            int numa = a[pa - 1], numb = b[pb - 1];
            if (numa < numb) {
                return findNum(a + pa, m - pa, b, n, k - pa);
            } else 
            if (numa > numb) {
                return findNum(a, m, b + pb, n - pb, k - pb);
            } else {
                return numa;
            }
        }
    }
};

int main() {
	return 0;
}