#include<iostream>
#include<vector>
using namespace std;

struct TNum {
    int number;
    int index;
};

bool compare(const TNum &x, const TNum &y) {
    return x.number < y.number;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        if (numbers.size() < 2) return ans;
        
        int n = numbers.size();
        vector<TNum> nums(n);
        for (int i=0; i<n; i++) {
            nums[i].number = numbers[i];
            nums[i].index = i;
        }
        std::sort(nums.begin(), nums.end(), compare);
        
        int i = 0, j = n - 1;
        while (i < j) {
            long long sum = (long long)nums[i].number + nums[j].number;
            if (sum == target) {
                int index1 = nums[i].index + 1;
                int index2 = nums[j].index + 1;
                if (index1 > index2) {
                    int temp = index1; index1 = index2; index2 = temp;
                }
                ans.push_back(index1);
                ans.push_back(index2);  
                return ans;
            } else 
            if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}