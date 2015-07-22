#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, char> mapST, mapTS;
        for (int i=0; i<s.length(); i++) {
            auto map_iter = mapST.find(s[i]);
            if (map_iter != mapST.end()) {
                if (map_iter->second != t[i]) return false;
            } else {
                mapST[s[i]] = t[i];
            }
            
            map_iter = mapTS.find(t[i]);
            if (map_iter != mapTS.end()) {
                if (map_iter->second != s[i]) return false;
            } else {
                mapTS[t[i]] = s[i];
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
