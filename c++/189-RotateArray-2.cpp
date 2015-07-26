#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        if (nums.size() <= 0) return;
        
        k = k % nums.size();
        if (k < 0) k += nums.size();
        if (k == 0) return;
        
        auto iter = nums.begin();
        int n1 = nums.size() - k, n2 = k;
        while (n1 > 0 && n2 > 0) {
            if (n1 <= n2) {
                swapSubArray(iter, n1);
                iter += n1;
                n2 -= n1;
            } else {
                swapSubArray(iter + n1 - n2, n2);
                n1 -= n2;
            }    
        }
    }
        
    inline void swapSubArray(vector<int>::iterator iter, int n) {
        for (int i=0; i<n; i++) {
            swap(iter[i], iter[i + n]);
        }
    }
};

int main() {
	return 0;
}
