#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        if (m == 0 || n != m) return;
        
        int midx = n / 2;
        int midy = (n + 1) / 2;
        for (int x = 0; x < midx; x++)
            for (int y = 0; y < midy; y++) {
                int newX = x, newY = y, newValue = matrix[x][y];
                for (int k = 0; k < 4; k++) {    
                    rotate(newX, newY, n);
                    int tmpValue = matrix[newX][newY];
                    matrix[newX][newY] = newValue;
                    newValue = tmpValue;
                }
            }
    }
    
    void rotate(int &x, int &y, const int n) {
        int tmp = x;
        x = y; 
        y = n - 1 - tmp;
    }
};

int main() {
	return 0;  
}