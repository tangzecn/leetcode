#include<iostream>
#include<vector>
using namespace std;

/*
  Add a leading and ending 1 to nums. Let's call the new list nums_new. 
  Suppose f[i][j] (j - i >= 2) means burst the balloons between (i, j) 
  to gain the maximal score. 
  Then f[i][j] = max{ 
    f[i][k] + f[k][j] + nums_new[i] * nums_new[k] * nums_new[j] }
    ( where i < k < j )
  The answer is f[0][news_new.size() - 1] 
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        vector<int> nums2;
        nums2.push_back(1);
        nums2.insert(nums2.end(), nums.begin(), nums.end());
        nums2.push_back(1);
        
        int n = nums2.size();
        vector<vector<int> > f(n, vector<int>(n, 0));
        for (int len=3; len<=n; len++) {
            for (int i=0; i<n-len+1; i++) {
                int j = i + len - 1;
                f[i][j] = INT_MIN;
                for (int k=i+1; k<j; k++) {
                    int s = f[i][k] + f[k][j] + nums2[i] * nums2[k] * nums2[j];
                    f[i][j] = max(f[i][j], s);
                }
            }
        }
        
        return f[0][n - 1];
    }
};

int main() {
    return 0;
}
