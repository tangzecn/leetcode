#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if (height.size() == 0) return 0;
        int n = height.size();
        
        vector<int> left(n, 0);
        stack<int> index;
        for (int i=0; i<n; i++) {
            while (!index.empty() && height[index.top()] >= height[i]) {
                index.pop();
            }
            if (index.empty()) {
                left[i] = 0;
            } else {
                left[i] = index.top() + 1;
            }
            index.push(i);
        }
        
        while (!index.empty()) index.pop();
        
        int right = n - 1;
        long long res = 0;
        for (int i=n-1; i>=0; i--) {
            while (!index.empty() && height[index.top()] >= height[i]) {
                index.pop();
            }   
            if (index.empty()) {
                right = n - 1;
            } else {
                right = index.top() - 1;
            }
            index.push(i);
            
            long long area = (long long)height[i] * (right - left[i] + 1);
            res = max(area, res);
        }
        
        return res;
    }
};

int main() {
	return 0;
}