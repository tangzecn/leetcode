#include<iostream>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        if (n <= 0) return true;
        
        int max_index = 0;
        for (int i = 0; i < n; i++) {
            if (i > max_index) return false;
            if (i + A[i] > max_index) {
                max_index = i + A[i];
                if (max_index >= n - 1) return true; 
            }
        }
        return max_index >= n - 1;
    }
};

int main() {
	return 0;
}