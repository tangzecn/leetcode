#include<iostream>
#include<set>
#include<vector>
using namespace std;

// Use multiset
class MedianFinder {
public:
	// Adds a number into the data structure.
    void addNum(int num) {
        smallHalf.insert(num);
        largeHalf.insert(*smallHalf.rbegin());
        smallHalf.erase(std::prev(smallHalf.end()));
        if (smallHalf.size() < largeHalf.size()) {
            smallHalf.insert(*largeHalf.begin());
            largeHalf.erase(largeHalf.begin());
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (smallHalf.size() == 0 && largeHalf.size() == 0) {
            return -1;
        } else
        if (smallHalf.size() == largeHalf.size()) {
            return (*smallHalf.rbegin() + *largeHalf.begin()) / 2.0;
        } else {
            return *smallHalf.rbegin();
        }
    }

private:
    multiset<int> smallHalf, largeHalf;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main() {
    return 0;
}
