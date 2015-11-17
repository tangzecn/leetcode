#include<iostream>
#include<vector>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int> > &matrix) {
        subSum.clear();
        if (matrix.size() > 0 && matrix[0].size() > 0) {
            subSum.resize(matrix.size(), vector<long long>(matrix[0].size(), 0));
            for (int i=0; i<matrix.size(); i++) {
                for (int j=0; j<matrix[i].size(); j++) {
                    subSum[i][j] = matrix[i][j] + calSubSum(i, j - 1) + calSubSum(i - 1, j) - calSubSum(i - 1, j - 1);
                }        
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 > row2 || col1 > col2) return 0;
        if (row1 < 0 || row2 >= subSum.size()) return 0;
        if (col1 < 0 || subSum.size() == 0 || col2 >= subSum[0].size()) return 0;
        return calSubSum(row2, col2) - calSubSum(row2, col1 - 1) - calSubSum(row1 - 1, col2) + calSubSum(row1 - 1, col1 - 1);
    }
    
    long long calSubSum(int i, int j) {
        return (i >= 0 && j >= 0) ? subSum[i][j] : 0;
    }
    
private:
    vector<vector<long long> > subSum;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

int main() {
    return 0;
}
