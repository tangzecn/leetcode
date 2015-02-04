#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end) return 1;
        
        dict.insert(end);
        dict.erase(start);
        queue<string> wordQueue;
        wordQueue.push(start);
        int step = 1;
        while (!wordQueue.empty()) {
            step++;
            int n = wordQueue.size();
            for (int i=0; i<n; i++) {
                string word = wordQueue.front();
                wordQueue.pop();
                for (int j=0; j<word.length(); j++) {
                    char originalCh = word[j];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == originalCh) continue;
                        word[j] = ch;
                        if (dict.find(word) != dict.end()) {
                            wordQueue.push(word);
                            dict.erase(word);
                            if (word == end) {
                                return step;
                            }
                        }
                    }    
                    word[j] = originalCh;
                }
            }
        }
        return 0;
    }
};

int main() {
	return 0;
}