#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        if (secret.length() == guess.length()) {
            vector<int> dCount(10, 0);
            for (int i=0; i<secret.length(); i++) {
                if (secret[i] == guess[i]) {
                    a++;
                } else {
                    dCount[secret[i] - 48]++;
                    dCount[guess[i] - 48]--;
                }
            }
            b = (secret.length() - a) << 1;
            for (int i=0; i<dCount.size(); i++) {
                b -= abs(dCount[i]);
            }
            b = b >> 1;
        }
        return std::to_string(a) + "A" + std::to_string(b) + "B";
    }
};

int main() {
    return 0;
}
