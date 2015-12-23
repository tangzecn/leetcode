#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> char_cnt;
        for (int i=0; i<s.length(); i++) {
            char_cnt[s[i]]++;
        }
        
        vector<string> res;
        int odd_cnt = 0;
        char odd_char;
        for (auto iter=char_cnt.begin(); iter!=char_cnt.end(); iter++) {
            if ((iter->second & 1) > 0) {
                odd_cnt++;
                odd_char = iter->first;
            }
        }
        if (odd_cnt <= 1) {
            dfs(char_cnt, s.length(), "", res, odd_char);
        }
        return res;
    }
    
private:
    void dfs(
        unordered_map<char, int> &char_cnt, 
        const int remain,
        string s,
        vector<string> &res,
        const char odd_char) {
        if (remain < 2) {
            if (remain == 1) {
                s.append(1, odd_char);
            }
            for (int i=s.length() - 1 - remain; i>=0; i--) {
                s.append(1, s[i]);
            }
            res.push_back(s);
        } else {
            for (auto iter=char_cnt.begin(); iter!=char_cnt.end(); iter++) {
                if (iter->second > 1) {
                    iter->second -= 2;
                    dfs(char_cnt, remain - 2, s + iter->first, res, odd_char);
                    iter->second += 2;
                }
            }
        }
    }
};

int main() {
    return 0;
}
