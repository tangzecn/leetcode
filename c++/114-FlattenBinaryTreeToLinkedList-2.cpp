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
        TreeNode *current = root;
        while (current != NULL) {
            if (current->left == NULL) {
                current = current->right;
            } else {
                TreeNode *leftSon = current->left;
                TreeNode *rightSon = current->right;
                current->left = NULL;
                current->right = leftSon;
                
                TreeNode *rightMost = leftSon;
                while (rightMost->right != NULL) {
                    rightMost = rightMost->right;
                }
                rightMost->right = rightSon;
                current = leftSon;
            }
        }
    }
};

int main() {
	return 0;
}