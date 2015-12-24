#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class TwoSum {
// private has to be put before public, or TLE, rediculous!
private:
    unordered_map<int, int> num_cnt;
public:
    // Add the number to an internal data structure.
    void add(int number) {
        num_cnt[number]++;
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for (auto iter_x=num_cnt.begin(); iter_x!=num_cnt.end(); iter_x++) {
            long long x = iter_x->first;
            long long y = (long long)value - x;
	    if (y < INT_MIN || y > INT_MAX) continue;
            if (x == y) {
                if (iter_x->second > 1) return true;
            } else {
                if (num_cnt.find(y) != num_cnt.end()) return true;
            }
        }
        return false;
    }
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);

int main() {
    return 0;
}
