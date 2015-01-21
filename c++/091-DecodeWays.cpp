#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (len < 1) return 0;
        
        int f0 = 1;
        int f1 = valid(s, 0, 1) ? 1 : 0;
        int f2;
        for (int i=1; i<len; i++) {
            f2 = 0;
            if (valid(s, i - 1, 2)) {
                f2 += f0;
            }
            if (valid(s, i, 1)) {
                f2 += f1;
            }
            f0 = f1;
            f1 = f2;
        }
        return f1;
    }
    
    bool valid(const string &s, int first, int count) {
        if (first < 0 || first >= s.length() || count < 0 || count > 2) return false;
        if (count > 1 && s[first] == '0') return false;
        int num = std::stoi(s.substr(first, count));
        return num >= 1 && num <= 26;
    }
};

int main() {
	return 0;
}