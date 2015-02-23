#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > strMap;
        for (int i=0; i<strs.size(); i++) {
            string keyStr = strs[i];
            if (keyStr.length() > 0) {
                sort(keyStr.begin(), keyStr.end());
            }
            strMap[keyStr].push_back(strs[i]);
        }
        
        vector<string> ans;
        unordered_map<string, vector<string> >::iterator it = strMap.begin();
        while (it != strMap.end()) {
            if (it->second.size() > 1) {
                for (int i=0; i<it->second.size(); i++) {
                    ans.push_back(it->second[i]);
                }
            }    
            it++;
        }
        return ans;
    }
};

int main() {
    return 0;
}
