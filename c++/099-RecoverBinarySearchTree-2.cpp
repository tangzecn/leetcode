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
        TreeNode *first = NULL, *second = NULL;
        
        TreeNode *prev = NULL, *curr = root, *rightMost = NULL;
        while (curr != NULL) {
            if (curr->left == NULL) {
                travelToNewNode(prev, curr, first, second);
                curr = curr->right;
            } else {
                rightMost = curr->left;
                while (rightMost->right != NULL && rightMost->right != curr) {
                    rightMost = rightMost->right;
                }
                if (rightMost->right == NULL) {
                    rightMost->right = curr;
                    curr = curr->left;
                } else {
                    rightMost->right = NULL;
                    travelToNewNode(prev, curr, first, second);
                    curr = curr->right;
                }
            }
        }
        if (first != NULL && second != NULL) {
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }
    
    void travelToNewNode(TreeNode *&prev, TreeNode *&curr, TreeNode *&first, TreeNode *&second) {
        if (prev != NULL && prev->val > curr->val) {
            if (first == NULL) {
                first = prev;
            }
            second = curr;
        }
        prev = curr;
    }
};

int main() {
	return 0;
}