#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        const int nB = buildings.size();
        
        priority_queue<pair<int, int> > liveB;
        vector<pair<int, int> > res;
        int i = 0, prevH = 0;
        while (i < nB || !liveB.empty()) {
            int currX = INT_MIN;
            if (liveB.empty() || (i < nB && buildings[i][0] <= liveB.top().second)) {
                currX = buildings[i][0];
                while (i < nB && buildings[i][0] == currX) {
                    liveB.push(make_pair(buildings[i][2], buildings[i][1]));
                    i++;
                }
            } else {
                currX = liveB.top().second;
                while (!liveB.empty() && liveB.top().second <= currX) {
                    liveB.pop();
                }
            }
            int currH = liveB.empty() ? 0 : liveB.top().first;
            if (prevH != currH) {
                res.push_back(make_pair(currX, currH));
                prevH = currH;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
