#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    // based on KMP algorithm
    string shortestPalindrome(string s) {
       if (s.length() == 0) return "";

       // s is the pattern string
       vector<int> next(s.length(), -1);
       int i = 0, j = -1;
       while (i + 1 < s.length()) {
           if (j < 0 || s[i] == s[j]) {
               i++; j++;
               if (s[i] == s[j]) {
                   next[i] = next[j]; 
               } else {
                   next[i] = j;
               }
           } else {
               j = next[j];
           }
       }
       
       // find s in rs
       string rs = s;
       std::reverse(rs.begin(), rs.end());       
       i = 0, j = 0;
       while (i < s.length()) {
           if (j < 0 || rs[i] == s[j]) {
               i++; j++;
           } else {
               j = next[j];    
           }
       }
       
       return rs.substr(0, rs.length() - j) + s;
    }
};

int main() {
    return 0;
}
