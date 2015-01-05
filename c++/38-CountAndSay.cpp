#include<iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string current = "1";
        for (int i=2; i<=n; i++) {
            string tmp = "";
            int j = 0;
            while (j < current.length()) {
                int k = j;
                while (k < current.length() && current[k] == current[j]) 
                    k++;
                tmp += std::to_string(k - j) + current[j];
                j = k;
            }
            current = tmp;
        }
        return current;
    }
};

int main() {
	return 0;
}