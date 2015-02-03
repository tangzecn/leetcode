#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> numSet;
        for (int i=0; i<num.size(); i++) {
            numSet.insert(num[i]);
        }
        int ans = 0;
        for (int i=0; i<num.size(); i++) {
            if (numSet.find(num[i]) != numSet.end()) {
                numSet.erase(num[i]);
                ans = max(ans, 1 + countConsecutive(numSet, num[i] - 1, false) 
                    + countConsecutive(numSet, num[i] + 1, true));
            }
        }
        return ans;
    }
    
    int countConsecutive(unordered_set<int> &numSet, int num, bool increase) {
        int count = 0;
        while (numSet.find(num) != numSet.end()) {
            numSet.erase(num);
            count++;
            if (increase) {
                num++;
            } else {
                num--;
            }
        }
        return count;
    }
};

int main() {
	return 0;
}