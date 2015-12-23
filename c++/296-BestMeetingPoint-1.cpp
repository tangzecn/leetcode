#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // use quick sort, O(NlogN) time
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
        res += calMinDist(x);
        res += calMinDist(y);
        return res;
    }

private:
    int calMinDist(vector<int> &x) {
        if (x.size() == 0) return 0;
        std::sort(x.begin(), x.end());
        int midX = x[x.size() >> 1];
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
