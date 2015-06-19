#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        
        vector<int> f(m, 0);
        int maxLength = 0;
        for (int i=0; i<n; i++) {
            int prev = 0;
            for (int j=0; j<m; j++) {
                int temp = f[j];
                if (matrix[i][j] == '0') {
                    f[j] = 0;
                } else {
                    if (i > 0 && j > 0) {
                        int length = min(min(f[j - 1], f[j]), prev);
                        f[j] = 1 + length;
                    } else {
                        f[j] = 1;
                    }
                }
                maxLength = max(maxLength, f[j]);
                prev = temp;
            }
        }
        return (long long)maxLength * maxLength;
    }
};

int main() {
    return 0;
}
