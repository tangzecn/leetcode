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
        
        for (int i=0; i<n; i++) 
            for (int j=i+1; j<n; j++) {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        int midn = n / 2;
        for (int i=0; i<n; i++) {
            for (int j=0; j<midn; j++) {
                int tmp = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }
};

int main() {
	return 0;  
}