#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size();
        long long res = 0;
        
        vector<int> height(m, 0);
        vector<int> left(m, 0);
        stack<int> index;
        int right = 0;
        for (int i=0; i<n; i++) {
            while (!index.empty()) index.pop();
            for (int j=0; j<m; j++) {
                height[j] = (matrix[i][j] == '1') ? ++height[j] : 0;
                while (!index.empty() && height[index.top()] >= height[j]) { 
                    index.pop();
                }
                if (index.empty()) {
                    left[j] = 0;
                } else {
                    left[j] = index.top() + 1;
                }
                index.push(j);
            }
            
            while (!index.empty()) index.pop();
            for (int j=m-1; j>=0; j--) {
                while (!index.empty() && height[index.top()] >= height[j]) { 
                    index.pop();
                }
                if (index.empty()) {
                    right = m - 1;
                } else {
                    right = index.top() - 1;
                }
                index.push(j);
                
                long long area = (long long)height[j] * (right - left[j] + 1);
                res = max(area, res);
            }
        }
        
        return res;
    }
};

int main() {
	return 0;
}