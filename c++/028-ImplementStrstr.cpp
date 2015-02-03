#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if (haystack == NULL || needle == NULL) return -1;
        int n = strlen(haystack);
        int m = strlen(needle);
        if (m == 0) return 0;
        if (n == 0) return -1;
        
        vector<int> next(m);
        next[0] = -1;
        int i = 0, j = -1;
        while (i < m - 1) {
            if (j < 0 || needle[i] == needle[j]) {
                i++; j++;
                if (needle[i] == needle[j]) {
                    next[i] = next[j];
                } else {
                    next[i] = j;
                }
            } else {
                j = next[j];
            }
        }
        
        i = -1; j = -1;
        while (i < n && j < m) {
            if (j < 0 || haystack[i] == needle[j]) {
                i++; j++;
            } else {
                j = next[j];
            }
        }
        
        if (j >= m) return i - j; else return -1;
    }
};

int main() {
	return 0;
}