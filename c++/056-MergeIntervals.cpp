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
 
bool compare(const Interval &interval1, const Interval &interval2) {
    return interval1.start < interval2.start;    
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        std::sort(intervals.begin(), intervals.end(), compare);
        
        vector<Interval> ans;
        int i = 0;
        while (i < intervals.size()) {
            Interval newInterval(intervals[i].start, intervals[i].end);
            int j = i + 1;
            while (j < intervals.size() && intervals[j].start <= newInterval.end) {
                newInterval.end = max(intervals[j].end, newInterval.end);
                j++;
            }
            ans.push_back(newInterval);
            i = j;
        }
        return ans;
    }
};

int main() {
	return 0;
}