#include<iostream>
#include<vector>
using namespace std;

bool comp(const int x, const int y) {
    return x > y;    
}

// Use pop_heap, push_heap
class MedianFinder {
public:
    MedianFinder() {
        smallHalf.clear();
        largeHalf.clear();
    }
    
    // Adds a number into the data structure.
    void addNum(int num) {
        // smallHalf.push(num)
        smallHalf.push_back(num);
        push_heap(smallHalf.begin(), smallHalf.end());
        // largeHalf.push(smallHalf.top())
        largeHalf.push_back(smallHalf.front());
        push_heap(largeHalf.begin(), largeHalf.end(), comp);
        // smallHalf.pop()
        pop_heap(smallHalf.begin(), smallHalf.end());
        smallHalf.pop_back();
        if (smallHalf.size() < largeHalf.size()) {
            // smallHalf.push(largeHalf.top())
            smallHalf.push_back(largeHalf.front());
            push_heap(smallHalf.begin(), smallHalf.end());
            // largeHalf.pop()
            pop_heap(largeHalf.begin(), largeHalf.end(), comp);
            largeHalf.pop_back();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (smallHalf.size() == 0 && largeHalf.size() == 0) {
            return -1;
        } else 
        if (smallHalf.size() == largeHalf.size()) {
            return (smallHalf.front() + largeHalf.front()) / 2.0;
        } else {
            return smallHalf.front();
        }
    }
    
private:
    vector<int> smallHalf, largeHalf;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main() {
	return 0;
}