#include<string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        if (len1 == 0 || len2 == 0) return "";
        
        string ans(len1 + len2, '0');
        for (int i = len1 - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = len2 - 1; j >= 0; j--) {
                carry = (num1[i] - 48) * (num2[j] - 48) + (ans[i + j + 1] - 48) + carry;
                ans[i + j + 1] = char((carry % 10) + 48);
                carry = carry / 10;
            }
            int k = i;
            while (carry > 0) {
                carry = (ans[k] - 48) + carry;
                ans[k] = char((carry % 10) + 48);
                carry = carry / 10;
                k--;
            }
        }
        while (ans[0] == '0' && ans.length() > 1) {
            ans.erase(ans.begin());
        }
        return ans;
    }
};

int main() {
    return 0;
}
