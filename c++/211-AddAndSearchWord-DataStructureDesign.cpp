#include<unordered_map>
#include<string>
using namespace std;

class TNode {
public:
    TNode() {
        sons.clear();
        isWord = false;
    }
    
    unordered_map<char, TNode*> sons;
    bool isWord;
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TNode();    
    }
    
    ~WordDictionary() {
        deleteTree(root);        
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        if (word.length() == 0) return;
        TNode *curr = root;
        for (int i=0; i<word.length(); i++) {
            unordered_map<char, TNode*>::iterator iter = curr->sons.find(word[i]);
            if (iter == curr->sons.end()) {
                TNode *newNode = new TNode();
                curr->sons[word[i]] = newNode;
                curr = newNode;
            } else {
                curr = iter->second;
            }
        }
        curr->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, root, 0);
    }

private:
    TNode *root;
    
    bool search(const string &word, const TNode *curr, int index) {
        if (index >= word.length()) {
            return curr->isWord;
        }
        if (word[index] == '.') {
            unordered_map<char, TNode*>::const_iterator iter = curr->sons.begin();
            while (iter != curr->sons.end()) {
                if (search(word, iter->second, index + 1)) return true;
                iter++;
            }
            return false;
        } else {
            unordered_map<char, TNode*>::const_iterator iter = curr->sons.find(word[index]);
            if (iter == curr->sons.end()) {
                return false;
            } else {
                return search(word, iter->second, index + 1);
            }
        }
    }
    
    void deleteTree(TNode *curr) {
        if (curr == NULL) return;
        for (auto iter = curr->sons.begin(); iter != curr->sons.end(); iter++) {
            deleteTree(iter->second);
        }
        curr->sons.clear();
        delete curr;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main() {
    return 0;
}
