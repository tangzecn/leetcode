#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > ans;
        unordered_map<string, int> stepMap;
        bfs(start, end, dict, stepMap);
        if (stepMap.find(end) != stepMap.end()) {    
            vector<string> solution(stepMap[end]);
            dfs(stepMap[end], end, stepMap, solution, ans);
        }
        return ans;       
    }
    
    void bfs(string start, string end, unordered_set<string> &dict, unordered_map<string, int> &stepMap) {
        dict.insert(end);
        dict.erase(start);
        stepMap[start] = 1;
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
                            stepMap[word] = step;
                            if (word == end) {
                                return;
                            }
                        }
                    }    
                    word[j] = originalCh;
                }
            }
        }        
    }
    
    void dfs(const int step, const string &currentWord, unordered_map<string, int> &stepMap, 
        vector<string> &solution, vector<vector<string> > &ans) {
        solution[step - 1] = currentWord;
        if (step == 1) {
            ans.push_back(solution);    
        } else {
            string word = currentWord;
            for (int i=0; i<word.length(); i++) {
                char originalCh = word[i];
                for (char ch='a'; ch<='z'; ch++) {
                    if (ch == originalCh) continue;
                    word[i] = ch;
                    unordered_map<string, int>::iterator it = stepMap.find(word);
                    if (it != stepMap.end() && it->second == step - 1) {
                        dfs(step - 1, word, stepMap, solution, ans);
                    }
                }
                word[i] = originalCh;
            }
        }
    }
};

int main() {
	return 0;
}