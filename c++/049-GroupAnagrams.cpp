#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > strMap;
        for (int i=0; i<strs.size(); i++) {
            string keyStr = strs[i];
            if (keyStr.length() > 0) {
                sort(keyStr.begin(), keyStr.end());
            }
            strMap[keyStr].push_back(strs[i]);
        }
        
        vector<vector<string> > ans;
        unordered_map<string, vector<string> >::iterator it = strMap.begin();
        while (it != strMap.end()) {
            sort(it->second.begin(), it->second.end());
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }
};

int main() {
    return 0;
}
