#include<algorithm>
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

class IntervalCompare {
public:
    bool operator() (const Interval& x, const Interval& y) {
        return (x.start < y.start) || (x.start == y.start && x.end < y.end);
    }
} inter_comp;

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), inter_comp);
        int curr_time = INT_MIN;
        for (int i=0; i<intervals.size(); i++) {
            if (curr_time > intervals[i].start) return false;
            curr_time = intervals[i].end;
        }
        return true;
    }
};

int main() {
    return 0;
}
