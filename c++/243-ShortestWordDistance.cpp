#include<stdlib.h>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1, res = INT_MAX;
        for (int i=0; i<words.size(); i++) {
            if (word1 == words[i]) p1 = i;
            if (word2 == words[i]) p2 = i;
            if (p1 >= 0 && p2 >= 0) {
                res = min(res, abs(p1 - p2));
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
