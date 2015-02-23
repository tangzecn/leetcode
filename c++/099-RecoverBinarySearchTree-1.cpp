#include<iostream>
using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *first = NULL, *second = NULL, *prev = NULL;
        recoverTree(root, prev, first, second);
        if (first != NULL && second != NULL) {
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }
    
    void recoverTree(TreeNode *node, TreeNode *&prev, TreeNode *&first, TreeNode *&second) {
        if (node == NULL) return;
        recoverTree(node->left, prev, first, second);
        if (prev != NULL && node->val < prev->val) {
            if (first == NULL) {
                first = prev;
            }    
            second = node;
        }
        prev = node;
        recoverTree(node->right, prev, first, second);
    }
};

int main() {
	return 0;
}