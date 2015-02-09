#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> f(s.length() + 1, false);
        f[s.length()] = true;
        for (int i=s.length() - 1; i>=0; i--) {
            for (int j=i; j<s.length(); j++) {
                if (f[j + 1] && dict.find(s.substr(i, j - i + 1)) != dict.end()) {
                    f[i] = true;
                    break;
                }
            }
        }   
        vector<string> ans, words;
        dfs(0, words, ans, f, s, dict);
        return ans;
    }
    
    void dfs(int startPos, vector<string> &words, vector<string> &ans, 
        const vector<bool> &f, const string &s, const unordered_set<string> &dict) {
        if (startPos == s.length()) {
            string solution = "";
            for (int i=0; i<words.size(); i++) {
                if (solution.length() > 0) {
                    solution.append(1, ' ');
                }
                solution.append(words[i]);
            }
            ans.push_back(solution);
        } else {
            for (int i=startPos; i<s.length(); i++) {
                if (f[i + 1]) {
                    string word = s.substr(startPos, i - startPos + 1);
                    if (dict.find(word) != dict.end()) {
                        words.push_back(word);
                        dfs(i + 1, words, ans, f, s, dict);
                        words.pop_back();
                    }
                }
            }
        }
    }
};

int main() {
	return 0;
}