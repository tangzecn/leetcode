#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        if (L.size() == 0 || L[0].length() == 0) return ans;
        
        unordered_map<string, int> wordCount;
        for (int i=0; i<L.size(); i++) {
            unordered_map<string, int>::iterator it = wordCount.find(L[i]);
            if (it == wordCount.end()) {
                wordCount[L[i]] = 1;
            } else {
                it->second++;
            }
        }
        
        int wordLen = L[0].length();
        int slen = S.length();
        for (int i=0; i<wordLen; i++) {
            int left = i, right = i, remainWordsCount = L.size();
            while (right + wordLen <= slen) {
                string word = S.substr(right, wordLen); 
                unordered_map<string, int>::iterator it = wordCount.find(word);
                if (it == wordCount.end()) {
                    while (left <= right) {
                        recoverWordCount(wordCount, S.substr(left, wordLen), remainWordsCount);
                        left += wordLen;
                    }
                } else {
                    while (it->second == 0) {
                        recoverWordCount(wordCount, S.substr(left, wordLen), remainWordsCount);
                        left += wordLen;
                    }
                    it->second--;
                    remainWordsCount--;
                    if (remainWordsCount == 0) {
                        ans.push_back(left);
                    }
                }
                right += wordLen;
            }
            while (left + wordLen <= slen) {
                recoverWordCount(wordCount, S.substr(left, wordLen), remainWordsCount);
                left += wordLen;    
            }
        }
        return ans;
    }
    
    void recoverWordCount(unordered_map<string, int> &wordCount, const string &word, int &remainWordsCount) {
        unordered_map<string, int>::iterator it = wordCount.find(word);
        if (wordCount.find(word) != wordCount.end()) {
            it->second++;
            remainWordsCount++;
        }
    }
};

int main() {
	return 0;
}