#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        int index = n - 1;
        while (index > 0 && num[index] <= num[index - 1]) {
            index--;
        }
        if (index == 0) {
            std::reverse(num.begin(), num.end());
        } else {
            std::reverse(num.begin() + index, num.end());
            for (int i=index; i<n; i++) {
                if (num[i] > num[index - 1]) {
                    swap(num[i], num[index - 1]);
                    break;
                }
            }
        }
    }
};

int main() {
	return 0;
}