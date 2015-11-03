#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> letterToWord;
        unordered_map<string, char> wordToLetter;
        int i = 0, st = 0, ed = 0;
        for (int i=0; i<pattern.size(); i++) {
            while (st < str.length() && !isalpha(str[st])) {
                st++;
            }
            if (st == str.length()) {
                return false;
            }
            ed = st;
            while (ed < str.length() && isalpha(str[ed])) {
                ed++;
            }
            string word = str.substr(st, ed - st);
            
            if (letterToWord[pattern[i]] == "" && wordToLetter[word] == 0) {
                letterToWord[pattern[i]] = word;
                wordToLetter[word] = pattern[i];
            } else 
            if (letterToWord[pattern[i]] != word || wordToLetter[word] != pattern[i]) {
                return false;
            }
            
            st = ed;
        }
        return (st == str.length());
    }
};

int main() {
    return 0;
}
