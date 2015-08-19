#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        static const vector<int> factor = {2, 3, 5};
        
        vector<int> index(factor.size(), 0);
        vector<int> res(1, 1);
        for (int i=1; i<n; i++) {
            int mins = INT_MAX;
            for (int j=0; j<factor.size(); j++) {
                mins = min(mins, res[index[j]] * factor[j]);
            }
            res.push_back(mins);
            for (int j=0; j<factor.size(); j++) {
                if (res[index[j]] * factor[j] == mins) {
                    index[j]++;
                }
            }
        }
        
        return *res.rbegin();
    }
};

int main() {
    return 0;
}