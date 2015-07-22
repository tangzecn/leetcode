#include<unordered_map>
#include<string>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        sons.clear();
        isWord = false;
    }
    unordered_map<char, TrieNode*> sons;
    bool isWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        deleteTree(root);    
    }
    
    // Inserts a word into the trie.
    void insert(const string &s) {
        if (s.length() <= 0) return;
        TrieNode *currNode = root;
        for (int i=0; i<s.length(); i++) {
            auto iter = currNode->sons.find(s[i]);
            if (iter == currNode->sons.end()) {
                TrieNode *newNode = new TrieNode();
                currNode->sons[s[i]] = newNode;
                currNode = newNode;
            } else {
                currNode = iter->second;
            }
        }
        currNode->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(const string &key) {
        TrieNode *node = searchNode(key);
        return (node != NULL) && (node->isWord);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(const string &prefix) {
        return searchNode(prefix) != NULL;
    }

private:
    TrieNode *root;
    
    TrieNode *searchNode(const string &prefix) {
        TrieNode *currNode = root;
        for (int i=0; i<prefix.length(); i++) {
            auto iter = currNode->sons.find(prefix[i]);
            if (iter == currNode->sons.end()) return NULL;
            currNode = iter->second;
        }
        return currNode;
    }
    
    void deleteTree(TrieNode *curr) {
        if (curr == NULL) return;
        for (auto iter = curr->sons.begin(); iter != curr->sons.end(); iter++) {
            deleteTree(iter->second);
        }
        curr->sons.clear();
        delete curr;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main() {
    return 0;
}
