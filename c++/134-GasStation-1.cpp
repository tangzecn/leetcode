#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        if (n <= 0) return -1;
    
        long long sumDiff = 0;
        int start = -1;
        for (int i=n-1; i>=0; i--) {
            long long diff = (long long)gas[i] - (long long)cost[i];
            while (diff < 0 && i > 0) {
                i--;
                diff += (long long)gas[i] - (long long)cost[i];
            }
            sumDiff += diff;
            if (diff >= 0) {
                start = i;
            }
        }
        return (sumDiff >= 0) ? start : -1;
    }
};

int main() {
	return 0;
}