#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

struct TrieTreeNode {
    unordered_map<char, TrieTreeNode*> sons;
    bool inDict;
    TrieTreeNode() : inDict(false) {}
};

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        TrieTreeNode *root = new TrieTreeNode();
        for (unordered_set<string>::iterator it=dict.begin(); it != dict.end(); it++) {
            addWord(root, *it);
        }
        
        vector<bool> f(s.length() + 1, false);
        f[s.length()] = true;
        for (int i=s.length() - 1; i>=0; i--) {
            int j = i;
            TrieTreeNode *currNode = root;
            unordered_map<char, TrieTreeNode*>::iterator it;
            while (j < s.length()) {
                it = currNode->sons.find(s[j]);
                if (it == currNode->sons.end()) break;
                currNode = it->second;
                if (f[j + 1] && currNode->inDict) {
                    f[i] = true; break;
                }
                j++;
            }
        }
        
        destroyTree(root);
        return f[0];
    }
    
    void addWord(TrieTreeNode *root, string word) {
        TrieTreeNode *currNode = root;
        for (int i=0; i<word.length(); i++) {
            unordered_map<char, TrieTreeNode*>::iterator it = currNode->sons.find(word[i]);
            if (it == currNode->sons.end()) {
                TrieTreeNode *newNode = new TrieTreeNode();
                currNode->sons[word[i]] = newNode;
                currNode = newNode;
            } else {
                currNode = it->second;
            }
        }
        currNode->inDict = true;
    }
    
    void destroyTree(TrieTreeNode *node) {
        if (node == NULL) return;
        unordered_map<char, TrieTreeNode*>::iterator it = node->sons.begin();
        while (it != node->sons.end()) {
            destroyTree(it->second);
            it++;
        }
        node->sons.clear();
        delete node;
    }
};

int main() {
	return 0;
}