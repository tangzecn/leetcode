#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    // Topological Sort
    string alienOrder(vector<string>& words) {
        unordered_set<char> chs;
        for (int i=0; i<words.size(); i++) 
            for (int j=0; j<words[i].length(); j++)
                chs.insert(words[i][j]);
                
        unordered_map<char, int> degree;
        for (auto iter=chs.begin(); iter!=chs.end(); iter++) 
            degree[*iter] = 0;
        
        unordered_map<char, vector<char> > g;
        for (int i=1; i<words.size(); i++) {
            if (words[i].empty() || words[i - 1].empty()) continue;
            int j = 0;
            while (j < words[i].length() && j < words[i - 1].length() && words[i][j] == words[i - 1][j]) {
                j++;
            }
            if (j >= words[i].length() || j >= words[i - 1].length()) continue;
            char x = words[i - 1][j];
            char y = words[i][j];
            g[x].push_back(y);
            degree[y]++;
        }
        
        string res;
        queue<char> candidates;
        for (auto iter=chs.begin(); iter!=chs.end(); iter++) 
            if (degree[*iter] == 0) {
                candidates.push(*iter);
            }
        while (!candidates.empty()) {
            char x = candidates.front();
            candidates.pop();
            res.append(1, x);
            if (g.find(x) != g.end()) {
                const vector<char> &sons = g.find(x)->second;
                for (int i=0; i<sons.size(); i++) {
                    char y = sons[i];
                    degree[y]--;
                    if (degree[y] == 0) {
                        candidates.push(y);
                    }
                }
            }
        }
        return (res.length() == chs.size()) ? res : "";
    }
};

int main() {
    return 0;
}
