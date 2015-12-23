#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string> > group_lists;
        for (int i=0; i<strings.size(); i++) {
            group_lists[getKey(strings[i])].push_back(strings[i]);
        }
        vector<vector<string> > res;
        for (auto iter = group_lists.begin(); iter != group_lists.end(); iter++) {
            res.push_back(iter->second);
            sort(res.rbegin()->begin(), res.rbegin()->end());
        }
        return res;
    }

private: 
    string getKey(string st) {
        if (st.empty()) return st;
        int shift = st[0] - 'a';
        for (int i=0; i<st.length(); i++) {
            st[i] -= shift;
            if (st[i] < 'a') st[i] += ('z' - 'a' + 1);
        }
        return st;
    }
};

int main() {
    return 0;
}
