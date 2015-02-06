#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2) return 0;
        
        int minNum = INT_MAX, maxNum = 0;
        for (int i=0; i<num.size(); i++) {
            minNum = min(num[i], minNum);
            maxNum = max(num[i], maxNum);
        }
        if (maxNum == minNum) return 0;
        
        int bucketSize = (int)ceil((double)(maxNum - minNum) / (num.size() - 1));
        vector<int> minBucket(num.size() - 1, INT_MAX);
        vector<int> maxBucket(num.size() - 1, INT_MIN);
        for (int i=0; i<num.size(); i++) {
            if (num[i] != maxNum) {
                int bucketNum = (num[i] - minNum) / bucketSize;
                minBucket[bucketNum] = min(num[i], minBucket[bucketNum]);
                maxBucket[bucketNum] = max(num[i], maxBucket[bucketNum]);
            }
        }
        
        int prevMax = minNum;
        int ans = 0;
        for (int i=0; i<num.size()-1; i++) {
            // can't write minBucket[i] < INT_MAX here, 
            // because INT_MAX may occur in the num list
            if (maxBucket[i] > INT_MIN) {
                ans = max(minBucket[i] - prevMax, ans);
                prevMax = maxBucket[i];
            }
        }
        ans = max(maxNum - prevMax, ans);
        return ans;
    }
};

int main() {
	return 0;
}