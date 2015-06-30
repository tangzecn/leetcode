#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0), left(m, -1), right(m, m);
        long long res = 0;
        for (int i=0; i<n; i++) {
            int curr_left = 0;
            for (int j=0; j<m; j++) {
                if (matrix[i][j] == '0') {
                    height[j] = 0;
                    left[j] = -1;
                    curr_left = j + 1;
                } else {
                    height[j]++;
                    left[j] = max(left[j], curr_left);
                }
            }
            int curr_right = m - 1;
            for (int j=m-1; j>=0; j--) {
                if (matrix[i][j] == '0') {
                    right[j] = m;
                    curr_right = j - 1;
                } else {
                    right[j] = min(right[j], curr_right);
                    long long area = (long long)height[j] * (right[j] - left[j] + 1);
                    res = max(res, area);
                }
            }
        }
        return res;
    }
};

int main() {
	return 0;
}