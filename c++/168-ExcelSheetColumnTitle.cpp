#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while (n > 0) {
            ans = char(65 + (n - 1) % 26) + ans;
            n = (n - 1) / 26;
        }  
        return ans;
    }
};

int main() {
	return 0;
}