#include<vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        
        int left = 0, right = citations.size() - 1;
        while (left < right) {
            int mid = (left & right) + ((left ^ right) >> 1);
            if (citations[mid] < citations.size() - mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (citations[left] >= citations.size() - left) {
            return citations.size() - left;
        } else {
            return 0;
        }
    }
};

int main() {
    return 0;
}