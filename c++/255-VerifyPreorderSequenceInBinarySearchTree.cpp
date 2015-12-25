#include<vector>
using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int ptr = 0, stack_size = 0, low = INT_MIN;
        while (ptr < preorder.size()) {
            if (preorder[ptr] < low) {
                return false;
            }
            while (stack_size > 0 && preorder[ptr] > preorder[stack_size - 1]) {
                low = preorder[stack_size - 1];
                stack_size--;
            }
            preorder[stack_size++] = preorder[ptr++];
        }
        return true;
    }
};

int main() {
    return 0;
}