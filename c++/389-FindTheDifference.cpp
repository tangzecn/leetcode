#include<iostream>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char res;
        for (int i=0; i<s.length(); i++) {
            res ^= s[i];
        }
        for (int i=0; i<t.length(); i++) {
            res ^= t[i];
        }
        return res;
    }
};

int main() {
    return 0;
}
