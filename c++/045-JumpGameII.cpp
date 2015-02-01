#include<iostream>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        if (n <= 0) return 0;
        
        int startPos = 0, endPos = 0, step = 0;
        while (startPos <= endPos && endPos < n - 1) {
            step++;
            int newEndPos = endPos;
            for (int i=startPos; i<=endPos; i++) {
                if (A[i] + i > newEndPos) {
                    newEndPos = A[i] + i;
                }
            }
            startPos = endPos + 1;
            endPos = newEndPos;
        }
        return (endPos >= n - 1) ? step : -1;
    }
};

int main() {
	return 0;
}