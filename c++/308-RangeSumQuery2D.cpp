#include<iostream>
#include<vector>
using namespace std;

struct TNodeY {
    int val, low, high;
    TNodeY *left, *right;
    TNodeY(int low, int high) {
        this->low = low;
        this->high = high;        
        this->val = 0;
        this->left = nullptr;
        this->right = nullptr;        
    }    
};

struct TNodeX {
    int low, high;
    TNodeY *rooty;
    TNodeX *left, *right;    
    TNodeX(int low, int high, TNodeY *rooty) {
        this->rooty = rooty;
        this->low = low;
        this->high = high;        
        this->left = nullptr;
        this->right = nullptr;          
    }
};

class NumMatrix {
public:
    NumMatrix(vector<vector<int> > &matrix) {
        n = matrix.size();
        m = (n > 0) ? matrix[0].size() : 0;
        if (n > 0 && m > 0) {
            this->matrix = matrix;
            vector<vector<int> > sum(n, vector<int>(m, 0));
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    sum[i][j] = matrix[i][j] + getValue(sum, i - 1, j) + 
                                getValue(sum, i, j - 1) - getValue(sum, i - 1, j - 1);
                }
            }
            rootx = constructTreeX(0, n - 1, 0, m - 1, sum);
        } else {
            rootx = nullptr;
        }
    }

    void update(int row, int col, int val) {
        if (rootx == nullptr) return;
        if (row < 0 || row >= n) return;
        if (col < 0 || col >= m) return;
        int diff = val - matrix[row][col];
        matrix[row][col] = val;
        updateTreeX(rootx, row, col, diff);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return queryTreeX(rootx, row1, row2, col1, col2);
    }
    
    ~NumMatrix() {
        destroyTreeX(rootx);    
    }
    
private:
    TNodeX* rootx;
    vector<vector<int> > matrix;
    int n, m;
    
    TNodeX *constructTreeX(int low1, int high1, int low2, int high2, 
                           const vector<vector<int> > &sum) {
        if (low1 > high1) {
            return nullptr;
        } else {
            TNodeY *rooty = constructTreeY(low1, high1, low2, high2, sum);
            TNodeX *nodex = new TNodeX(low1, high1, rooty);
            if (low1 < high1) {
                int mid = getMid(low1, high1);
                nodex->left = constructTreeX(low1, mid, low2, high2, sum);
                nodex->right = constructTreeX(mid + 1, high1, low2, high2, sum);
            }
            return nodex;
        }
    }
    
    TNodeY *constructTreeY(int low1, int high1, int low2, int high2, 
                           const vector<vector<int> > &sum) {
        if (low2 > high2) {
            return nullptr;
        } else {
            TNodeY *nodey = new TNodeY(low2, high2);
            if (low2 == high2) {
                nodey->val = getValue(sum, high1, high2) - getValue(sum, high1, low2 - 1) - 
                             getValue(sum, low1 - 1, high2) + getValue(sum, low1 - 1, low2 - 1);
            } else {
                int mid = getMid(low2, high2);
                nodey->left = constructTreeY(low1, high1, low2, mid, sum);
                nodey->right = constructTreeY(low1, high1, mid + 1, high2, sum);
                nodey->val = ((nodey->left != nullptr) ? nodey->left->val : 0) + 
                             ((nodey->right != nullptr) ? nodey->right->val : 0);
            }
            return nodey;
        }
    }
                               

    void updateTreeX(TNodeX* nodex, const int row, const int col, const int diff) {
        updateTreeY(nodex->rooty, col, diff);
        if (nodex->low < nodex->high) {
            int mid = getMid(nodex->low, nodex->high);
            if (row <= mid) {
                updateTreeX(nodex->left, row, col, diff);
            } else {
                updateTreeX(nodex->right, row, col, diff);
            }
        }
    }
    
    void updateTreeY(TNodeY* nodey, const int col, const int diff) {
        if (nodey->low == nodey->high) {
            nodey->val += diff;
        } else {
            int mid = getMid(nodey->low, nodey->high);
            if (col <= mid) {
                updateTreeY(nodey->left, col, diff);
                nodey->val += diff;
            } else {
                updateTreeY(nodey->right, col, diff);
                nodey->val += diff;
            }
        }
    }

    int queryTreeX(TNodeX *nodex, int low1, int high1, int low2, int high2) {
        if (nodex == nullptr || high1 < nodex->low || low1 > nodex->high) {
            return 0;
        } else if (low1 <= nodex->low && high1 >= nodex->high) {
            return queryTreeY(nodex->rooty, low2, high2);
        } else {
            return queryTreeX(nodex->left, low1, high1, low2, high2) + 
                   queryTreeX(nodex->right, low1, high1, low2, high2);
        }
    }
    
    int queryTreeY(TNodeY *nodey, int low, int high) {
        if (nodey == nullptr || high < nodey->low || low > nodey->high) {
            return 0;
        } else if (low <= nodey->low && high >= nodey->high) {
            return nodey->val;
        } else {
            return queryTreeY(nodey->left, low, high) + queryTreeY(nodey->right, low, high);
        }
    }
    
    void destroyTreeX(TNodeX *nodex) {
        if (nodex == nullptr) return;
        destroyTreeX(nodex->left);
        destroyTreeX(nodex->right);
        destroyTreeY(nodex->rooty);
        delete nodex;
    }
    
    void destroyTreeY(TNodeY *nodey) {
        if (nodey == nullptr) return;
        destroyTreeY(nodey->left);
        destroyTreeY(nodey->right);
        delete nodey;
    }
    
    inline int getMid(int low, int high) {
        return low + ((high - low) >> 1);
    }    
    
    inline int getValue(const vector<vector<int> > &matrix, int x, int y) {
        if (x < 0 || x >= matrix.size()) return 0;
        if (y < 0 || y >= matrix[0].size()) return 0;
        return matrix[x][y];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);

int main() {
    return 0;
}