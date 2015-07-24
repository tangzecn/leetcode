#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution {
public:
    // Greedy + KMP, real O(N+M)
    bool isMatch(const char *s, const char *p) {
        if (s == NULL || p == NULL) return false;
        
        int lens = strlen(s), lenp = strlen(p);
        
        while (lens > 0 && lenp > 0 && (s[lens - 1] == p[lenp - 1] || p[lenp - 1] == '?')) {
            lens--; lenp--;
        }
        // there is no '*' in p
        if (lenp == 0) {
            return lens == 0;
        } else {
            if (p[lenp - 1] != '*') return false;
        }
        
        const char *points = s, *pointp = p;
        while (lenp > 0) {
            int keyLen = 0;
            while (*pointp != '*') {
                keyLen++;
                pointp++;
                lenp--;
            }
            if (keyLen > 0) {
                int matchPos = kmp(points, lens, pointp - keyLen, keyLen);
                if (matchPos < 0 || (pointp - keyLen == p && matchPos != keyLen)) {
                    return false; 
                } else {
                    points += matchPos;
                    lens -= matchPos;
                }
            }
            pointp++;
            lenp--;
        }
        return true;
    }
    
    int kmp(const char* s, int lens, const char *p, int lenp) {
        vector<int> next(lenp);
        next[0] = -1;
        int i = 0, j = -1;
        while (i < lenp - 1) {
            if (j < 0 || p[i] == p[j] || p[j] == '?') {
                i++; j++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
        i = -1; j = -1;
        while (i < lens && j <lenp) {
            if (j < 0 || s[i] == p[j] || p[j] == '?') {
                i++; j++;
            } else {
                j = next[j];
            }
        }
        if (j >= lenp) return i; else return -1;
    }
};

int main() {
	return 0;
}
