#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, int> chCount;
        for (int i=0; i < s.length(); i++) {
            chCount[s[i]]++;
        }
        for (int i=0; i < t.length(); i++) {
            auto iter = chCount.find(t[i]);
            if (iter == chCount.end()) return false;
            iter->second--;
        }
        for (auto iter = chCount.begin(); iter != chCount.end(); iter++) {
            if (iter->second != 0) return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
