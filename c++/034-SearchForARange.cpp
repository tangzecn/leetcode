#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ans;
        
        int left = 0, right = n - 1, mid;
        while (left < right) {
            mid = (left + right) >> 1;
            if (A[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        if (left >= n || A[left] != target) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        } else {
            ans.push_back(left);
        }
        
        left = 0; right = n - 1;
        while (left < right) {
            mid = (left + right + 1) >> 1;
            if (A[mid] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        ans.push_back(left);
        
        return ans;
    }
};

int main() {
	return 0;
}