#include<iostream>
#include<vector>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct TPoint {
    int pos;
    bool isStart;
    TPoint(int _pos, bool _isStart) : pos(_pos), isStart(_isStart) {}
};

class TPointCompare {
public:
    bool operator() (const TPoint &x, const TPoint &y) {
        return x.pos < y.pos;
    }
} point_comp;

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<TPoint> points;
        for (int i=0; i<intervals.size(); i++) {
            points.push_back(TPoint(intervals[i].start, true));
            points.push_back(TPoint(intervals[i].end, false));
        }
        sort(points.begin(), points.end(), point_comp);
        
        int res = 0, curr_room = 0, i = 0;
        while (i < points.size()) {
            int j = i;
            while (j < points.size() && points[j].pos == points[i].pos) {
                if (points[j].isStart) {
                    curr_room++;
                } else {
                    curr_room--;
                }
                j++;
            }
            res = max(res, curr_room);
            i = j;
        }
        return res;
    }
};

int main() {
    return 0;
}