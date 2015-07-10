#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    // based on Manacher's algorithm
    string shortestPalindrome(string s) {
        if (s.empty()) return "";
        
        string rs = s;
        std::reverse(rs.begin(), rs.end());
        
        string rs1 = preProcess(rs);
        vector<int> p(rs1.length(), 1);
        int id = -1, mx = -1, startPos = -1, maxLen = 0;
        for (int i=0; i<rs1.length(); i++) {
            p[i] = (mx > i) ? min(p[2 * id - i], mx - i) : 1;
            int left = i - p[i], right = i + p[i];
            while (left >= 0 && right < rs1.length() && rs1[left] == rs1[right]) {
                p[i]++;
                left--;
                right++;
            }
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
                if (mx >= rs1.length()) break;
            }
        }
        return rs.substr(0, rs.length() - (p[id] - 1)) + s;
    }

    string preProcess(const string &s) {
        string s1(s.length() * 2 + 1, '#');
        for (int i=0; i<s.length(); i++) {
            s1[i * 2 + 1] = s[i];
        }
        return s1;
    }
};

int main() {
    return 0;
}
