#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        int n = matrix.size(), m = matrix[0].size();
        int x = 0, y = m - 1;
        while (x < n && y >= 0) {
            if (matrix[x][y] == target) return true;
            else if (matrix[x][y] < target) x++;
            else y--;
        }
        return false;
    }
};

int main() {
    return 0;
}
