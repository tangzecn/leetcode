#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    // Greedy + KMP, real O(N+M)
    bool isMatch(string s, string p) {
        // match right most part
        int lenS = s.length(), lenP = p.length();
        while (lenS > 0 && lenP > 0 && (s[lenS - 1] == p[lenP - 1] || p[lenP - 1] == '?')) {
            lenS--; lenP--;
        }
        // there is no '*' in p
        if (lenP == 0) {
            return lenS == 0;
        } else {
            if (p[lenP - 1] != '*') return false;
        }
        
        // gready+kmp algorithm, match left most and between '*' parts
        int is = 0, ip = 0;
        while (ip < lenP) {
            int lenSubP = 0;
            while (p[ip + lenSubP] != '*') {
                lenSubP++;
            }
            if (lenSubP > 0) {
                int matchPos = kmp(s, is, lenS - is, p, ip, lenSubP);
                // not match or not match on position 0 for the first segment
                if (matchPos < 0 || (ip == 0 && matchPos != 0)) {
                    return false; 
                } else {
                    is += matchPos + lenSubP;
                }
            }
            ip += lenSubP + 1;
        }
        return true;
    }
    
    // find subP matching in subS
    int kmp(const string&s, int is, int lenSubS, const string &p, int ip, int lenSubP) {
        vector<int> next(lenSubP);
        next[0] = -1;
        int i = 0, j = -1;
        while (i < lenSubP - 1) {
            if (j < 0 || p[ip + i] == p[ip + j] || p[ip + j] == '?') {
                i++; j++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
        i = -1; j = -1;
        while (i < lenSubS && j < lenSubP) {
            if (j < 0 || s[is + i] == p[ip + j] || p[ip + j] == '?') {
                i++; j++;
            } else {
                j = next[j];
            }
        }
        if (j == lenSubP) return i - lenSubP; else return -1;
    }
};

int main() {
	return 0;
}
