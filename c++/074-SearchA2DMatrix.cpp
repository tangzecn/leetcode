#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        if (n == 0 || matrix[0].size() == 0) return false;
        int m = matrix[0].size();
        
        if (matrix[0][0] > target) return false;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (matrix[mid][0] == target) return true;
            else 
            if (matrix[mid][0] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        int row = right;
        if (matrix[row][m - 1] < target) return false;
        left = 0; right = m - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (matrix[row][mid] == target) return true;
            else 
            if (matrix[row][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

int main() {
	return 0;
}