#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
      if (strs.size() <= 0) return "";
      string ans = "";
      for (int i=0; i<strs[0].length(); i++) {
        bool matchAll = true;
        for (int j=1; j<strs.size(); j++) {
            if (i >= strs[j].length() || strs[0][i] != strs[j][i]) {
                matchAll = false;
                break;
            }
        }
        if (!matchAll) break;
        ans.append(1, strs[0][i]);
      }
      return ans;
    }
};

int main() {
    return 0;
}
