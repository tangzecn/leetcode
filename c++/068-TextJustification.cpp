#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans;
        int n = words.size();
        int start = 0;
        while (start < n) {
            int end = start + 1, totLen = words[start].length();
            while (end < n && totLen + words[end].length() + (end - start) <= L) {
                totLen += words[end].length();
                end++;
            }
            int totWord = end - start;
            int totSpace = L - totLen;
            int baseGap, extraSpace;
            if (end < n) {
                baseGap = totWord > 1 ? (totSpace) / (totWord - 1) : 0;
                extraSpace = totWord > 1 ? totSpace - baseGap * (totWord - 1) : 0;
            } else {
                baseGap = 1;
                extraSpace = 0;
            }
            string line="";
            for (int i=start; i<end; i++) {
                line.append(words[i]);
                if (i + 1 < end) {
                    if (extraSpace > 0) {
                        line.append(baseGap + 1, ' ');
                        extraSpace--;
                    } else {
                        line.append(baseGap, ' ');
                    }
                }
            }
            if (line.length() < L) {
                line.append(L - line.length(), ' ');
            }
            ans.push_back(line);
            start = end;
        }
        return ans;
    }
};

int main() {
	return 0;
}