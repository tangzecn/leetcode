#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans(n, ' ');
        if (n <= 0) return ans;
        
        int factorial = 1;
        for (int i=1; i<n; i++) {
            factorial *= i;
        }
        
        vector<char> digit(n, 0);
        for (int i=0; i<n; i++) {
            digit[i] = '1' + i;  
        }
        
        k--;
        for (int i=n; i>=1; i--) {
            int count = k / factorial;
            k %= factorial;
            ans[n - i] = digit[count];
            digit.erase(digit.begin() + count);
            if (i > 1) {
                factorial /= (i - 1);
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}