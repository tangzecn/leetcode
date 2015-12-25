#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> mp_word;
        unordered_set<string> words; 
        return wordPatternMatch(0, 0, pattern, str, mp_word, words);
    }
    
private:
    bool wordPatternMatch(int ptr_p, int ptr_s, const string &pattern, const string& str, 
        unordered_map<char, string> &mp_word, unordered_set<string> words) {
        if (ptr_p == pattern.length() || ptr_s == str.length()) {
            return ptr_p == pattern.length() && ptr_s == str.length();
        } else {
            auto map_iter = mp_word.find(pattern[ptr_p]);
            if (map_iter != mp_word.end()) {
                const string &word = map_iter->second;
                if (ptr_s + word.length() <= str.length() && 
                    str.substr(ptr_s, word.length()) == word) {
                    return wordPatternMatch(ptr_p + 1, ptr_s + word.length(), 
                                            pattern, str, mp_word, words);                
                } else {
                    return false;
                }
            } else {
                int high = str.length() - (pattern.length() - ptr_p) + 1;
                for (int i=ptr_s; i<high; i++) {
                    string word = str.substr(ptr_s, i - ptr_s + 1);
                    if (words.find(word) != words.end()) continue;
                    mp_word[pattern[ptr_p]] = word;
                    words.insert(word);
                    if (wordPatternMatch(ptr_p + 1, i + 1, pattern, str, mp_word, words)) {
                        return true;
                    }
                    words.erase(word);
                }
                mp_word.erase(pattern[ptr_p]);
                return false;
            }
        }
    }
};

int main() {
    return 0;
}