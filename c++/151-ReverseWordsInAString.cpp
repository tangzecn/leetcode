#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int len = s.length();
        reverse(s.begin(), s.end());

        int i = 0, index = 0;
        while (i < len) {
            int j = i;
            while (j < len && s[j] != ' ') {
                j++;
            }
            if (i < j) {
                reverse(s.begin() + i, s.begin() + j);
                if (index > 0) {
                    s[index] = ' ';
                    index++;
                }
                for (int k = i; k < j; k++) {
                    s[index]  = s[k];
                    index++;
                }
            }
            i = j + 1;
        }
        if (index < len) {
            s.erase(index, len - index);
        }
    }
};

int main() {
	return 0;
}