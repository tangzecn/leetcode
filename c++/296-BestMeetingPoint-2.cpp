#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // use bucket sort, O(N) time
    int minTotalDistance(vector<vector<int> >& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        
        vector<int> x, y;
        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        
        int res = 0;
        res += calMinDist(x, grid.size());
        res += calMinDist(y, grid[0].size());
        return res;
    }

private:
    int calMinDist(const vector<int> &x, const int n) {
        if (x.size() == 0) return 0;
        
        vector<int> bucket(n, 0);
        for (int i=0; i<x.size(); i++) {
            bucket[x[i]]++;
        }
        
        int midX = -1, cnt = 0;
        for (int i=0; i<n; i++) {
            cnt += bucket[i];
            if (cnt > (x.size() >> 1)) {
                midX = i; 
                break;
            }
        }
        
        int minDist = 0;
        for (int i=0; i<x.size(); i++) {
            minDist += abs(x[i] - midX);
        }
        return minDist;
    }
};

int main() {
    return 0;
}
