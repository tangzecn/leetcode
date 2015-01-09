#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        long long ans = 0;
        
        int left = 0, right = height.size() - 1;
        while (left < right) {
            long long minHeight = min(height[left], height[right]);
            long long volume = (long long)(right - left) * minHeight;
            ans = max(ans, volume);
            if (height[left] <= height[right]) {
                while (left < right && height[left] <= minHeight) {
                    left++;
                }
            } else {
                while (left < right && height[right] <= minHeight) {
                    right--;
                }
            }
        }
        
        return ans;
    }
};

int main() {
	return 0;
}
