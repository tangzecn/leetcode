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
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        univalSubtree(root, res);
        return res;
    }
    
private:
    bool univalSubtree(TreeNode *node, int &res) {
        bool isUnivalSubtree = true;
        if (node != nullptr) {
            if (node->left != nullptr) {
                bool isLeftUnival = univalSubtree(node->left, res);
                isUnivalSubtree = isUnivalSubtree && isLeftUnival && (node->val == node->left->val);
                                  
            }
            if (node->right != nullptr) {
                bool isRightUnival = univalSubtree(node->right, res);
                isUnivalSubtree = isUnivalSubtree && isRightUnival && (node->val == node->right->val);
            }
            if (isUnivalSubtree) res++;
        }
        return isUnivalSubtree;
    }
};

int main() {
    return 0;
}