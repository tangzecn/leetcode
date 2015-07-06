#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // merge sort
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        return divide(buildings, 0, buildings.size() - 1);
    }

private:
    vector<pair<int, int> > divide(const vector<vector<int> >& buildings, int start, int end) {
        vector<pair<int, int> > res, leftRes, rightRes;
        if (start > end) return leftRes;
        if (start == end) {
            addNode(res, buildings[start][0], buildings[start][2]);
            addNode(res, buildings[start][1], 0);
            return res;
        }
        
        int mid = (start + end) >> 1;
        leftRes = divide(buildings, start, mid);
        rightRes = divide(buildings, mid + 1, end);
        int i = 0, j = 0, leftH = 0, rightH = 0;
        while (i < leftRes.size() && j < rightRes.size()) {
            if (leftRes[i].first < rightRes[j].first) {
                leftH = leftRes[i].second;
                addNode(res, leftRes[i].first, max(leftH, rightH)); 
                i++;    
            } else if (leftRes[i].first > rightRes[j].first) {
                rightH = rightRes[j].second;
                addNode(res, rightRes[j].first, max(leftH, rightH));
                j++;
            } else {
                leftH = leftRes[i].second;
                rightH = rightRes[j].second;
                addNode(res, leftRes[i].first, max(leftH, rightH));
                i++; j++;
            }
        }
        while (i < leftRes.size()) {
            addNode(res, leftRes[i].first, leftRes[i].second); 
            i++;
        }
        while (j < rightRes.size()) {
            addNode(res, rightRes[j].first, rightRes[j].second); 
            j++;
        }
        
        return res;
    }
    
    void addNode(vector<pair<int, int> > &res, int x, int h) {
        if (res.empty() || h != res.rbegin()->second) {
            res.push_back(make_pair(x, h));
        }
    }
};

int main() {
    return 0;
}
