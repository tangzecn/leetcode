#include<iostream>
#include<vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        long long sum = 0;
        subSum.clear();
        subSum.push_back(sum);
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
            subSum.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return (i >= 0 && i <= j && j < subSum.size() - 1) ? subSum[j + 1] - subSum[i] : 0; 
    }

private:
    vector<long long> subSum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main() {
    return 0;
}
