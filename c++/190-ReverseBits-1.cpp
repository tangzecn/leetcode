#include<iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        static const int digit_num = 32;
        uint32_t ans = 0;
        for (int i=0; i<digit_num; i++) {
            ans = (ans << 1) | (n & 1);
            n = n >> 1;
        }
        return ans;
    }
};

int main() {
    return 0;
}
