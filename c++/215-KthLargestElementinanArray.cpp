#include<vector>
#include<cstdlib>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k--;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int i = left, j = right, x = nums[rand() % (right - left + 1) + left];
            while (i <= j) {
                while (nums[i] > x) i++;
                while (nums[j] < x) j--;
                if (i <= j) {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    i++; j--;
                }
            }
            if (j >= left && k <= j) right = j;
            else
            if (i <= right && k >= i) left = i;
            else
            return nums[k];
        }
        // invalid k
        return -1;
    }
};

int main() {
    return 0;
}
