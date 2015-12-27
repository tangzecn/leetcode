#include<vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0);
        for (int i=0; i<n; i++) {
            if (citations[i] <= n) {
                count[citations[i]]++;
            } else {
                count[n]++;
            }
        }
        
        for (int i=n; i>0; i--) {
            if (count[i] >= i) return i;
            count[i - 1] += count[i];
        }
        return 0;
    }
};

int main() {
    return 0;
}