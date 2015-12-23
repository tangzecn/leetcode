#include<string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        std::reverse(s.begin(), s.end());
        int i = 0;
        while (i < s.length()) {
            if (s[i] != ' ') {
                int j = i;
                while (j < s.length() && s[j] != ' ') j++;
                std::reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            } else {
                i++;
            }
        }
    }
};

int main() {
    return 0;
}