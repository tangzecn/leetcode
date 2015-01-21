#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int len = s.length();
        for (int i=1; i<4 && i<len-2; i++) {
            if (!valid(s, 0, i)) continue;
            for (int j=i+1; j<i+4 && j<len-1; j++) {
                if (!valid(s, i, j)) continue;
                for (int k=j+1; k<j+4 && k<len; k++) {
                    if (!valid(s, j, k) || !valid(s, k, len)) continue;
                    ans.push_back(s.substr(0, i) + "." + s.substr(i, j - i) + 
                        "." + s.substr(j, k - j) + "." + s.substr(k, len - k));  
                }
            }
        }
        return ans;
    }
    
    bool valid(const string &s, const int first, const int last) {
        if (first >= last || last - first > 3) return false;
        if (last - first > 1 && s[first] == '0') return false;
        int num = std::stoi(s.substr(first, last - first));
        return num >= 0 && num <= 255;
    }
};

int main() {
    Solution solution;
    solution.restoreIpAddresses("0000");
    return 0;
}
