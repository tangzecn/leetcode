#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
      int ans = 0;
      int tot = 0;
      for (int i=0; i<num.size(); i++) {
        if (tot == 0) {
          ans = num[i]; 
          tot = 1;
        } else if (ans == num[i]) {
          tot++;
        } else {
          tot--;
        }
      }
      return ans;
    }
};

int main() {
    return 0;
}
