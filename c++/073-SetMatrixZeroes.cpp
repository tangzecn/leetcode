#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n < 1) return;
        int m = matrix[0].size();
        if (m < 1) return;
        
        bool firstRowZero = false;
        for (int j=0; j<m; j++)
            firstRowZero |= (matrix[0][j] == 0);
        bool firstColumnZero = false;
        for (int i=0; i<n; i++)
            firstColumnZero |= (matrix[i][0] == 0);
            
        for (int i=1; i<n; i++) 
            for (int j=1; j<m; j++)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        for (int i=1; i<n; i++) 
            for (int j=1; j<m; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
        for (int j=0; j<m; j++)
            if (firstRowZero) {
                matrix[0][j] = 0;
            }
        for (int i=0; i<n; i++) {
            if (firstColumnZero) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
	return 0;
}