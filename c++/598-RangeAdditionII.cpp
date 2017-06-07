#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int> >& ops) {
        int res_m = m, res_n = n;
        for (int i=0; i<ops.size(); i++) {
            res_m = min(res_m, ops[i][0]);
            res_n = min(res_n, ops[i][1]);
        }
        return res_m * res_n;
    }
};

int main() {
    return 0;
}
