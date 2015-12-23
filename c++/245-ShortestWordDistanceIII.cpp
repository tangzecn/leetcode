#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX;
        if (word1 != word2) {
            int p1 = -1, p2 = -1;
            for (int i=0; i<words.size(); i++) {
                if (word1 == words[i]) p1 = i;
                if (word2 == words[i]) p2 = i;
                if (p1 >= 0 && p2 >= 0) {
                    res = min(res, abs(p1 - p2));
                }
            }
        } else {
            int p = -1;
            for (int i=0; i<words.size(); i++) {
                if (word1 == words[i]) {
                    if (p > -1) {
                        res = min(res, abs(i - p));
                    }
                    p = i;
                }
            }
        }
        return res;        
    }
};

int main() {
    return 0;
}
