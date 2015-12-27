#include<iostream>
#include<vector>
using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    cachedNext = 0;
	    hasCache = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (hasCache) {
            return cachedNext;
        } else if (Iterator::hasNext()) {
            hasCache = true;
            cachedNext = Iterator::next();
            return cachedNext;
        } else {
            // should not reach here.
            return -1;
        }
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int nextNum = peek();
        hasCache = false;
        return nextNum;
	}

	bool hasNext() const {
	    return hasCache || Iterator::hasNext();
	}
private:
    int cachedNext;
    bool hasCache;
};

int main() {
    return 0;
}