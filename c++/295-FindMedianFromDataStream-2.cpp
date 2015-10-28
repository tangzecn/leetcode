#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Comp {
public:
    Comp(const bool _reverse = false) : reverse(_reverse) {}

    bool operator() (const int x, const int y) {
        if (reverse) {
            return x > y;
        } else {
            return x < y;
        }
    }
private:
    bool reverse;
};

typedef priority_queue<int, vector<int>, Comp> queue_type;

// Use priority_queue
class MedianFinder {
public:
	MedianFinder() : smallHalf(Comp(false)), largeHalf(Comp(true)) {
	}

    // Adds a number into the data structure.
    void addNum(int num) {
        smallHalf.push(num);
        largeHalf.push(smallHalf.top());
        smallHalf.pop();
        if (smallHalf.size() < largeHalf.size()) {
            smallHalf.push(largeHalf.top());
            largeHalf.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (smallHalf.size() == 0 && largeHalf.size() == 0) {
            return -1;
        } else
        if (smallHalf.size() == largeHalf.size()) {
            return (smallHalf.top() + largeHalf.top()) / 2.0;
        } else {
            return smallHalf.top();
        }
    }

private:
    queue_type smallHalf, largeHalf;
};

int main() {
    return 0;
}
