#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> ch_cnt;
        int res = 0, left_ptr = 0;
        for (int right_ptr=0; right_ptr<s.length(); right_ptr++) {
            ch_cnt[s[right_ptr]]++;
            while (left_ptr <= right_ptr && ch_cnt.size() > DIST_CHAR_LIMIT) {
                char ch = s[left_ptr];
                int cnt = --ch_cnt[ch];
                if (cnt == 0) {
                    ch_cnt.erase(ch);
                }
                left_ptr++;
            }
            res = max(res, right_ptr - left_ptr + 1);
        }
        return res;
    }

private:
    static const int DIST_CHAR_LIMIT = 2;
};

int main() {
    return 0;
}