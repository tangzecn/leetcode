#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // use cache and block to optimize
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i=0; i<N_BLOCK; i++) {
            uint32_t block = n & ((1 << BLOCK_SIZE) - 1);
            n >>= BLOCK_SIZE;
            ans = (ans << BLOCK_SIZE) | reverseBlock(block);
        }
        return ans;
    }
private:
    static const int BLOCK_SIZE = 8 * sizeof(unsigned char);
    static const int N_BLOCK = (8 * sizeof(uint32_t)) / BLOCK_SIZE;
    static vector<int> reverseMap;
    
    inline uint32_t reverseBlock(uint32_t block) {
        if (reverseMap[block] < 0) {
            uint32_t rBlock = 0, tmpBlock = block;
            for (int i=0; i<BLOCK_SIZE; i++) {
                rBlock = (rBlock << 1) | (tmpBlock & 1);
                tmpBlock >>= 1;
            }
            reverseMap[block] = rBlock;
        }
        return reverseMap[block];
    }
};

vector<int> Solution::reverseMap(1 << Solution::BLOCK_SIZE, -1);

int main() {
    return 0;
}
