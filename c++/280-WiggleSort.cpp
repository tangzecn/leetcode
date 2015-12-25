#include<vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool increase = true;
        for (int i=1; i<nums.size(); i++) {
            if ((increase && nums[i] < nums[i - 1]) || (!increase && nums[i] > nums[i - 1])) {
                std::swap(nums[i], nums[i - 1]);
            }
            increase = !increase;
        }
    }
};

int main() {
    return 0;
}