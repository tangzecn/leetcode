#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        vector<int> tmp_count(nums.size(), 0);
        vector<int> tmp_nums(nums.size(), 0);
        vector<int> index(nums.size(), 0);
        vector<int> tmp_index(nums.size(), 0);
        vector<int> res(nums.size(), 0);
        for (int i=0; i<nums.size(); i++) {
            index[i] = i;
        }
        
        mergeSort(0, nums.size() - 1, nums, count, tmp_nums, tmp_count, index, tmp_index);
        
        for (int i=0; i<nums.size(); i++) {
            res[index[i]] = count[i];   
        }
    
        return res;
    }
    
    void mergeSort(
        const int left, 
        const int right, 
        vector<int> &nums, 
        vector<int> &count,
        vector<int> &tmp_nums,
        vector<int> &tmp_count,
        vector<int> &index,
        vector<int> &tmp_index) {
        if (left > right) return;
        
        if (left == right) {
            count[left] = 0;
            return;
        } else {
            int mid = left + ((right - left) >> 1);
            mergeSort(left, mid, nums, count, tmp_nums, tmp_count, index, tmp_index);
            mergeSort(mid + 1, right, nums, count, tmp_nums, tmp_count, index, tmp_index);
            
            for (int i=left; i<=right; i++) {
                tmp_nums[i] = 0;
                tmp_count[i] = 0;
                tmp_index[i] = 0;
            }
            
            int i = left, j = mid + 1, k = left;
            while (i <= mid || j <= right) {
                if ((j > right) || (i <= mid && nums[i] <= nums[j])) {
                    tmp_nums[k] = nums[i];
                    tmp_count[k] = count[i] + (j - mid - 1);
                    tmp_index[k] = index[i];
                    i++; k++;
                } else {
                    tmp_nums[k] = nums[j];
                    tmp_count[k] = count[j];
                    tmp_index[k] = index[j];
                    j++; k++;
                }
            }
            
            for (int i=left; i<=right; i++) {
                nums[i] = tmp_nums[i];
                count[i] = tmp_count[i];
                index[i] = tmp_index[i];
            }
        }
    }
};

int main() {
    return 0;
}