#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool canWin(string s) {
        unordered_map<string, bool> win_map;
        return canWin(s, win_map);
    }
    
private: 
    bool canWin(string s, unordered_map<string, bool> &win_map) {
        auto iter = win_map.find(s);
        if (iter != win_map.end()) {
            return iter->second;
        } else {
            bool can_win = false;
            for (int i=1; i<s.length(); i++) {
                if (s[i] == '+' && s[i - 1] == '+') {
                    string new_s = s;
                    new_s[i - 1] = '-';
                    new_s[i] = '-';
                    if (!canWin(new_s, win_map)) {
                        can_win = true;
                        break;
                    }
                }
            }
            win_map[s] = can_win;
            return can_win;
        }
    }
};

int main() {
    return 0;
}