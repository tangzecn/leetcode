#include<iostream>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int lens = S.length(), lent = T.length();
        int *f = new int[lent + 1];
        f[0] = 1;
        for (int i=1; i<=lent; i++)
            f[i] = 0;
        for (int i=1; i<=lens; i++) {
            for (int j=lent; j>0; j--) {
                if (S[i - 1] == T[j - 1]) {
                    f[j] += f[j - 1];
                }
            }
        }
        
        int ans = f[lent];
        delete[] f;
        return ans;
    }
};

int main() {
	return 0;
}