#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // DP:
    // f[i][0] means the minimal cost to paint house 0 .. i, 
    // and color[i][0] means the color of house i to reach cost f[i][0];
    // f[1][1] means the second minimal cost to paint house 0 .. i,  
    // and color[i][1] means the color of house i to reach cost f[i][1];
    // Time O(NK), extra Space O(1)
    int minCostII(vector<vector<int> >& costs) {
        if (costs.size() == 0 || costs[0].size() == 0) return 0;
        
        int n = costs.size(), k = costs[0].size();
        vector<vector<long long> > f(2, vector<long long>(2, LONG_MAX));
        vector<vector<int> > color(2, vector<int>(2, -1));
        for (int i=0; i<k; i++) {
            updateF(costs[0][i], i, f[0], color[0]);
        }
        for (int i=1; i<n; i++) {
            int last_index = (i + 1) & 1, curr_index = i & 1;
            f[curr_index][0] = LONG_MAX; color[curr_index][0] = -1;
            f[curr_index][1] = LONG_MAX; color[curr_index][1] = -1;
            for (int j=0; j<k; j++) {
                long long curr_cost = LONG_MAX;
                if (color[last_index][0] != j) {
                    curr_cost = f[last_index][0];
                } else {
                    curr_cost = f[last_index][1];
                }
                if (curr_cost < LONG_MAX) {
                    curr_cost += costs[i][j];
                    updateF(curr_cost, j, f[curr_index], color[curr_index]);
                }
            }
        }
        
        int index = (n - 1) & 1;
        if (f[index][0] < LONG_MAX) {
            return f[index][0];
        } else {
            return -1;
        }
    }
    
private:
    void updateF(long long curr_cost, int curr_color, vector<long long> &f, vector<int> &color) {
        if (curr_cost < f[0]) {
            f[1] = f[0];
            color[1] = color[0];
            f[0] = curr_cost;
            color[0] = curr_color;
        } else if (curr_cost < f[1]) {
            f[1] = curr_cost;
            color[1] = curr_color;
        }
    }
};

int main() {
    return 0;
}
