#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        if (n <= 0) return -1;
    
        int start = 0, end = 0;
        long long sumDiff = 0;
        while (start < n && end - start < n) {
            long long diff = (long long)gas[end % n] - (long long)cost[end % n];
            sumDiff += diff;
            if (sumDiff < 0) {
                start = end + 1;
                sumDiff = 0;
            } 
            end++;
        }
        return (start < n) ? start : -1;
    }
};

int main() {
	return 0;
}