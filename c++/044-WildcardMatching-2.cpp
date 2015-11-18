#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
    // Greedy, fake O(n + m)
    bool isMatch(string s, string p) {
        int lens = s.length(), lenp = p.length();
        int indexs = 0, indexp = 0;
        int lastStar = -1, matchStart = -1;
        while (indexs < lens) {
            if (indexp < lenp && (s[indexs] == p[indexp] || p[indexp] == '?')) {
                indexs++; indexp++;
            } else
            if (indexp < lenp && p[indexp] == '*') {
                lastStar = indexp;
                matchStart = indexs;
                indexp++;
            } else 
            if (lastStar != -1) {
                indexs = matchStart + 1;
                matchStart++;
                indexp = lastStar + 1;
            } else {
                return false;
            }
        }
        while (indexp < lenp && p[indexp] == '*') {
            indexp++;
        }
        return (indexp == lenp);
    }  
};

int main() {
	return 0;
}
