#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() == 0) return -1;
        
        long long sumDiff = 0;
        long long minSumDiff = LLONG_MAX;
        int start = -1;
        for (int i=0; i<gas.size(); i++) {
            long long diff = (long long)gas[i] - (long long)cost[i];
            sumDiff += diff;
            if (sumDiff < minSumDiff) {
                minSumDiff = sumDiff;
                start = (i + 1) % gas.size();
            }
        }
        return (sumDiff >= 0) ? start : -1;
    }
};

int main() {
	return 0;
}