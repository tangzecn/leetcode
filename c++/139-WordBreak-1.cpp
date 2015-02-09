#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> f(s.length() + 1, false);
        f[s.length()] = true;
        for (int i=s.length() - 1; i>=0; i--) {
            for (int j=i+1; j<=s.length(); j++) {
                if (f[j] && dict.find(s.substr(i, j - i)) != dict.end()) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[0];
    }
};

int main() {
	return 0;
}