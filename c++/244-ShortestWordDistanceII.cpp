#include<iostream>
#include<stdlib.h>
#include<unordered_map>
#include<vector>
using namespace std;

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i=0; i<words.size(); i++) {
            word_pos[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        if (word_pos.find(word1) == word_pos.end()) return INT_MAX;
        if (word_pos.find(word2) == word_pos.end()) return INT_MAX;
        const vector<int> &pos1 = word_pos.find(word1)->second;
        const vector<int> &pos2 = word_pos.find(word2)->second;
        int i = 0, j = 0, res = INT_MAX;
        while (i < pos1.size() && j < pos2.size()) {
            res = min(res, abs(pos1[i] - pos2[j]));
            if (pos1[i] <= pos2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
    
private:
    unordered_map<string, vector<int> > word_pos;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");

int main() {
    return 0;
}
