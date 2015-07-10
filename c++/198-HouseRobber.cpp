#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
        long long ans = 0;
        long long f0 = 0, f1 = 0, f2;
        for (int i = 0; i<num.size(); i++) {
            f2 = max(f1, f0 + num[i]);
            f0 = f1;
            f1 = f2;
        }
        return f1;
    }
};

int main() {
    return 0;
}
