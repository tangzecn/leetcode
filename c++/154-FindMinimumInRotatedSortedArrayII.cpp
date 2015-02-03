#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.size() <= 0) return -1;
        int left = 0, right = num.size() - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (num[left] < num[right]) {
                return num[left];
            } else
            if (num[left] == num[mid] && num[left] == num[right]) {
                left++;
            } else 
            if (num[mid] >= num[left]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return num[left];        
    }
};

int main() {
	return 0;
}