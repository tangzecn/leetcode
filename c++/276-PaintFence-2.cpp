#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // DP: f[i] means number of ways paint from post 1 to post i 
    // f[0] = 1, f[1] = k, f[2] = k * k
    // f[i] = f[i - 1] * (k - 1) + f[i - 2] * (k - 1);  (for i >= 3)
    // f[i - 1] * (k - 1) means the last two posts have different color
    // f[i - 2] * (k - 1) means the last two posts have the same color
    // 
    // Use Matrix Multiplication
    // Let A = |  (k - 1),  (k - 1)  |
    //         |     1   ,     0     |
    // For i >= 3
    // A^(i - 2) *  |  f[2]  |   =   |  f[i]      | 
    //              |  f[1]  |       |  f[i - 1]  |
    //
    // Time O(logN), Extra Space O(1)
    int numWays(int n, int k) {
        if (n <= 0 || k <= 0) return 0;
        if (n == 1) return k;
        if (n == 2) return k * k;
        
        vector<vector<int> > matrix(2, vector<int>(2, 0));
        matrix[0][0] = k - 1;
        matrix[0][1] = k - 1;
        matrix[1][0] = 1;
        
        vector<vector<int> > res(2, vector<int>(2, 0));
        res[0][0] = 1;
        res[1][1] = 1;
        n -= 2;
        while (n > 0) {
            if (n & 1) {
                res = multiply(res, matrix);
            }
            n = n >> 1;
            if (n > 0) {
                matrix = multiply(matrix, matrix);
            }
        }

        return res[0][0] * (k * k) + res[0][1] * k;
    }

private:
    vector<vector<int> > multiply(const vector<vector<int> > &x, const vector<vector<int> > &y) {
        vector<vector<int> > res(x.size(), vector<int>(y[0].size()));
        for (int i=0; i<x.size(); i++) 
            for (int j=0; j<y[0].size(); j++)
                for (int k=0; k<x[0].size(); k++) {
                    res[i][j] += x[i][k] * y[k][j];
                }
        return res;
    }
};

int main() {
    return 0;
}
