#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class TrieNode {
public:
    TrieNode() : wordIndex(-1), nWord(0), parent(NULL) {}
    
    unordered_map<char, TrieNode*> sons;
    int wordIndex, nWord;
    TrieNode *parent;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> res;
        if (board.size() == 0 || board[0].size() == 0) return res;
        
        TrieNode *root = new TrieNode();
        for (int i=0; i<words.size(); i++)
            insertWord(root, words[i], i);
            
        for (int i=0; i<board.size(); i++) 
            for (int j=0; j<board[0].size(); j++) {
                dfs(words, board, i, j, root, res);
            }

        deleteTree(root);
        return res;
    }

private:    
    void dfs(const vector<string>& words, vector<vector<char> >& board, int x, int y, TrieNode *lastNode, vector<string> &res) {
        auto iter = lastNode->sons.find(board[x][y]);
        if (iter == lastNode->sons.end()) return;
        TrieNode *currNode = iter->second;
        if (currNode->nWord <= 0) return;
        
        if (currNode->wordIndex >= 0) {
            res.push_back(words[currNode->wordIndex]);
            currNode->wordIndex = -1;
            
            TrieNode *node = currNode;
            while (node != NULL) {
                node->nWord--;
                node = node->parent;
            }
        }
        
        char tmpChar = board[x][y];
        board[x][y] = ' ';
        static const int move_x[4] = {-1, 1, 0, 0};
        static const int move_y[4] = {0, 0, -1, 1};
        for (int i=0; i<4; i++) {
            int newx = x + move_x[i];
            int newy = y + move_y[i];
            if (newx < 0 || newx >= board.size() || newy < 0 || newy >= board[0].size()) continue;
            if (board[newx][newy] == ' ') continue;
            dfs(words, board, newx, newy, currNode, res);
        }
        board[x][y] = tmpChar;
    }

    void insertWord(TrieNode *root, const string &word, int wordIndex) {
        TrieNode *currNode = root;
        for (int i=0; i<word.length(); i++) {
            auto iter = currNode->sons.find(word[i]);
            if (iter == currNode->sons.end()) {
                TrieNode *newNode = new TrieNode();
                newNode->parent = currNode;
                currNode->sons[word[i]] = newNode;
                currNode = newNode;
            } else {
                currNode = iter->second;
            }
        }
        if (currNode->wordIndex < 0) {
            currNode->wordIndex = wordIndex;
            while (currNode != NULL) {
                currNode->nWord++;
                currNode = currNode->parent;
            }
        }
    }
    
    void deleteTree(TrieNode *currNode) {
        if (currNode == NULL) return;
        for (auto iter = currNode->sons.begin(); iter != currNode->sons.end(); iter++) {
            deleteTree(iter->second);
        }
        delete currNode;
    }
};

int main() {
    return 0;
}
