#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int low = max(0, int(k - nums2.size()));
        int high = min((int)nums1.size(), k);
        vector<int> res;
        for (int i=low; i<=high; i++) {
            vector<int> maxNum1 = getMaxNum(nums1, i);
            vector<int> maxNum2 = getMaxNum(nums2, k - i);
            vector<int> maxNum = merge(maxNum1, maxNum2);
            if (larger(maxNum, 0, res, 0)) {
                res.assign(maxNum.begin(), maxNum.end());
            }
        }
        return res;
    }
    
private:
    vector<int> getMaxNum(const vector<int> &num, int k) {
        vector<int> maxNum(k, 0);
        int ptr = 0;
        for (int i=0; i<num.size(); i++) {
            while (ptr > 0 && ptr + (num.size() - i - 1) >= k && num[i] > maxNum[ptr - 1]) {
                ptr--;
            }
            if (ptr < k) {
                maxNum[ptr++] = num[i];
            }
        }
        return maxNum;
    }
    
    vector<int> merge(const vector<int> &num1, const vector<int> &num2) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < num1.size() || j < num2.size()) {
            if (j == num2.size() || (i < num1.size() && larger(num1, i, num2, j))) {
                res.push_back(num1[i]);
                i++;
            } else {
                res.push_back(num2[j]);
                j++;
            }
        }
        return res;
    }
    
    bool larger(const vector<int> &num1, int start1, const vector<int> &num2, int start2) {
        int i = start1, j = start2;
        while (i < num1.size() && j < num2.size()) {
            if (num1[i] > num2[j]) {
                return true;
            } else if (num1[i] < num2[j]) {
                return false;
            }
            i++; j++;
        }
        return i < num1.size();
    }
};

int main() {
    return 0;
}