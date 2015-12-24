#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    bool canWin(string s) {
        vector<int> initial_states;
        int max_n = 0;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '+') {
                int n = 0;
                while (i < s.length() && s[i] == '+') {
                    i++; n++;
                }
                initial_states.push_back(n);
                max_n = max(max_n, n);
            }
        }
        vector<int> g(max_n + 1, 0);
        for (int i=1; i<=max_n; i++) {
            unordered_set<int> g_values;
            for (int j=2; j<=i; j++) {
                g_values.insert(g[j - 2] ^ g[i - j]);
            }
            g[i] = 0;
            while (g_values.find(g[i]) != g_values.end()) {
                g[i]++;
            }
        }
        int g_value = 0;
        for (int i=0; i<initial_states.size(); i++) {
            g_value ^= g[initial_states[i]];
        }
        return g_value != 0;
    }
};

int main() {
    return 0;
}