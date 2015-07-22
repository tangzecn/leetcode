#include<iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int diffCount = 0;
        while (n != m) {
            n >>= 1;
            m >>= 1;
            diffCount++;
        }
        return n << diffCount;
    }
};

int main() {
    return 0;
}
