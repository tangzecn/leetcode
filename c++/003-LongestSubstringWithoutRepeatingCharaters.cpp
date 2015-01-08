#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len < 1) return 0;
        
        const int MAX_CHAR = 1 << 8;
        int index[MAX_CHAR];
        for (int i=0; i<MAX_CHAR; i++) 
            index[i] = -1;
            
        int i = 0, j = 0, ans = 0;
        while (i < len) {
            while (j < len && index[s[j]] < 0) {
                index[s[j]] = j;
                j++;
            }
            if (j - i > ans) {
                ans = j - i;
            }
            
            index[s[i]] = -1;
            i++;
        }
        
        return ans;
    }
};

int main() {
	return 0;
}