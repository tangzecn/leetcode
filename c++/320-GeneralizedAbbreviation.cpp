#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        dfs(0, word, "", res, false);
        return res;
    }
    
private: 
    void dfs(int ptr, const string &word, string solution, vector<string> &res, bool lastIsNum) {
        if (ptr >= word.length()) {
            res.push_back(solution);
        } else {
            dfs(ptr + 1, word, solution + word[ptr], res, false);
            if (!lastIsNum) {
                for (int i=ptr; i<word.length(); i++) {
                    dfs(i + 1, word, solution + std::to_string(i - ptr + 1), res, true);
                }
            }
        }
    }
};

int main() {
    return 0;
}