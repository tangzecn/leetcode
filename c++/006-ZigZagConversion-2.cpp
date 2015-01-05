#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows < 1 || s.length() < 1) return "";
        if (nRows == 1) return s;
        
        string ans;
        ans.reserve(s.length());
        for (int i=0; i<nRows; i++) {
            int index = i;
            while (index < s.length()) {
                ans.append(1, s[index]);
                if (i > 0 && i + 1 < nRows) {
                    int index2 = index + (nRows - 1 - i) * 2;
                    if (index2 < s.length()) {
                        ans.append(1, s[index2]);
                    }
                }
                index += (nRows - 1) * 2;
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}