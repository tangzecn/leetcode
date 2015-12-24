#include<iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Suppose every value is unique in the tree
    // Time complexity O(h), space complexity O(1)
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *succ = nullptr;
        if (p->right != nullptr) {
            succ = p->right;
            while (succ->left != nullptr) {
                succ = succ->left;
            }
        } else {
            TreeNode *node = root;
            while (node != nullptr) {
                if (p->val < node->val) {
                    succ = node;
                    node = node->left;
                } else if (p->val > node->val) {
                    node = node->right;
                } else {
                    // since every value is unique, p should equal to node here
                    break;
                }
            }
        }
        return succ;
    }
};

int main() {
    return 0;
}
