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
    // Suppose there can be duplicate values in the tree.
    // Time complexity O(n)
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool visitedP = false;
        return inorderSuccessor(root, p, visitedP);
    }
    
private:
    TreeNode* inorderSuccessor(
        TreeNode* node, 
        TreeNode* p, 
        bool &visitedP) {

        if (node == nullptr) {
            return nullptr;
        } else if (node == p) {
            visitedP = true;
            return inorderSuccessor(node->right, p, visitedP);
        } else {
            TreeNode* succ = nullptr;
            // find P or succ of P in left sub tree
            if (visitedP || p->val <= node->val) {
                succ = inorderSuccessor(node->left, p, visitedP);
            }
            // when succ of P is not in left sub tree
            if (succ == nullptr) {
                if (visitedP) {
                    succ = node;
                } else {
                    succ = inorderSuccessor(node->right, p, visitedP);
                }
            }
            return succ;
        }
    }
};

int main() {
    return 0;
}