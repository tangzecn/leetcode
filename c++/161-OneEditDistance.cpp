#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        return changeOneCh(s, t) || addOneCh(s, t) || addOneCh(t, s);
    }
    
private:
    bool changeOneCh(const string &s, const string &t) {
        if (s.length() != t.length()) return false;
        bool changed = false;
        for (int i=0; i<s.length(); i++) {
            if (s[i] != t[i]) {
                if (changed) {
                    return false;
                } else {
                    changed = true;
                }
            }
        }
        return changed;
    }
    
    bool addOneCh(const string &s, const string &t) {
        if (s.length() != t.length() - 1) return false;
        int i = 0;
        while (i < s.length() && s[i] == t[i]) i++;
        i++;
        while (i < t.length() && s[i - 1] == t[i]) i++;
        return i == t.length();
    }
};

int main() {
    return 0;
}