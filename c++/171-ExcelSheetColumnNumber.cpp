#include<iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for (int index = 0; index < s.length(); index++) {
            ans = ans * 26 + (s[index] - 64);
        }    
        return ans;
    }
};

int main() {
	return 0;
}