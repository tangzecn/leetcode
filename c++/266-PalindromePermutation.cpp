#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> letter_cnt;
        for (int i=0; i<s.length(); i++) {
            letter_cnt[s[i]]++;
        }
        int odd_cnt = 0;
        for (auto iter=letter_cnt.begin(); iter!=letter_cnt.end(); iter++) {
            if ((iter->second & 1) > 0) {
                odd_cnt++;
            }
        }
        return odd_cnt <= 1;
    }
};

int main() {
    return 0;
}
