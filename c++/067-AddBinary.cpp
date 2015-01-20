#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.length();
        int lenb = b.length();
        string ans(max(lena, lenb), ' ');
        int extra = 0;
        for (int indexa = lena - 1, indexb = lenb - 1, index = ans.length() - 1; 
            index >= 0; indexa--, indexb--, index--) {
            int digita = indexa >= 0 ? a[indexa] - 48 : 0;
            int digitb = indexb >= 0 ? b[indexb] - 48 : 0;
            extra = extra + digita + digitb;
            ans[index] = (extra & 1) + 48;
            extra = extra >> 1;
        }
        if (extra > 0) {
            ans.insert(ans.begin(), (char)extra + 48);
        }
        return ans;
    }
};

int main() {
	return 0;
}