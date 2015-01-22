#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if (n <= 0) {
            return vector<vector<int> >(0);
        }
        vector<vector<int> > ans(n, vector<int>(n));
        
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int count = 1;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                ans[top][i] = count++;
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                ans[i][right] = count++;
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans[bottom][i] = count++;
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans[i][left] = count++;
                }
                left++;
            }
        }
        return ans;        
    }
};

int main() {
	return 0;
}