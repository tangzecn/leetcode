#include<iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serialize(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return deserialize(data, index);    
    }
    
private:
    static const char SEPERATOR = ',';
    
    void serialize(TreeNode* node, string& s) {
        if (node != NULL) {
            s.append(std::to_string(node->val));
            s.append(1, SEPERATOR);
            serialize(node->left, s);
            serialize(node->right, s);
        } else {
            s.append(1, SEPERATOR);
        }
    }
    
    TreeNode* deserialize(const string& data, int& index) {
        TreeNode *node = nullptr;
        if (index < data.length()) {
            int st = index;
            while (data[index] != SEPERATOR) {
                index++;
            }
            if (index > st) {
                node = new TreeNode(std::stoi(data.substr(st, index - st)));
                index++;
                node->left = deserialize(data, index);
                node->right = deserialize(data, index);
            } else {
                index++;
            }
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    return 0;
}
