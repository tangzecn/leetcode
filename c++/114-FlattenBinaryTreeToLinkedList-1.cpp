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
    void flatten(TreeNode *root) {
        flattenAndGetTail(root);
    }
    
    TreeNode *flattenAndGetTail(TreeNode *root) {
        if (root == NULL) return NULL;
        if (root->left != NULL) {
            TreeNode *leftTail = flattenAndGetTail(root->left);
            leftTail->right = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode *rightTail = flattenAndGetTail(leftTail->right);
            if (rightTail != NULL) return rightTail; else return leftTail;
        } else 
        if (root->right != NULL) {
            return flattenAndGetTail(root->right);
        } else {
            return root;
        }
    }
};

int main() {
	return 0;
}