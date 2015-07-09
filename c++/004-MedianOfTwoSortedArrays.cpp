#include<iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if ((n + m) & 1) {
            return findMedian(nums1.begin(), nums2.begin(), n, m, (n + m + 1) >> 1);
        } else {
            return double(findMedian(nums1.begin(), nums2.begin(), n, m, (n + m) >> 1) + 
                findMedian(nums1.begin(), nums2.begin(), n, m, (n + m + 2) >> 1)) / 2.0;
        }
    }
    
    int findMedian(vector<int>::iterator num1, vector<int>::iterator num2, int n, int m, int k) {
        if (n > m) return findMedian(num2, num1, m, n, k);
        else
        if (n == 0) return *(num2 + k - 1);
        else
        if (k == 1) return min(*num1, *num2);
        else {
            int n1 = (k / 2 <= n) ? k / 2 : n;
            int m1 = k - n1;
            if ((*(num1 + n1 - 1)) < (*(num2 + m1 - 1))) {
                return findMedian(num1 + n1, num2, n - n1, m, k - n1);
            } else if ((*(num1 + n1 - 1)) > (*(num2 + m1 - 1))) {
                return findMedian(num1, num2 + m1, n, m - m1, k - m1);
            } else {
                return *(num1 + n1 - 1);
            }
        }
    }
};

int main() {
	return 0;
}