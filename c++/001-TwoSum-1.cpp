#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

struct TNum {
    int number;
    int index;
};

void qsort(TNum *nums, int left, int right) {
    if (left >= right) return;
    int i = left, j = right, x = nums[left + rand() % (right - left + 1)].number;
    while (i <= j) {
        while (nums[i].number < x) i++;
        while (nums[j].number > x) j--;
        if (i <= j) {
            TNum temp = nums[i]; nums[i] = nums[j]; nums[j] = temp;
            i++; j--;
        }
    }
    qsort(nums, left, j); qsort(nums, i, right);
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        if (numbers.size() < 2) return ans;
        
        int n = numbers.size();
        TNum *nums = new TNum[n];
        for (int i=0; i<n; i++) {
            nums[i].number = numbers[i];
            nums[i].index = i;
        }
        qsort(nums, 0, n - 1);
        
        for (int i = 0, j = n - 1; i < n && i < j; i++) {
            while (i < j && (long long)nums[i].number + nums[j].number > (long long)target) {
                j--;
            }
            if (i < j && (long long)nums[i].number + nums[j].number == (long long)target) {
                int index1 = nums[i].index + 1;
                int index2 = nums[j].index + 1;
                if (index1 > index2) {
                    int temp = index1; index1 = index2; index2 = temp;
                }
                ans.push_back(index1);
                ans.push_back(index2);
                delete[] nums;
                return ans;
            }
        }
        
        delete[] nums;
        return ans;
    }
};

int main() {
	return 0;
}