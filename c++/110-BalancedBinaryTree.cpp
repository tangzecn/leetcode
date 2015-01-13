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
    bool isBalanced(TreeNode *root) {
        bool isBalanced = true;
        return (getHeight(root) < 0) ? false : true;
    }
    
    int getHeight(const TreeNode *root) {
        if (root == NULL) return 0;
        int leftHeight = getHeight(root->left);
        if (leftHeight < 0) return -1;
        int rightHeight = getHeight(root->right);
        if (rightHeight < 0) return -1;
        return abs(leftHeight - rightHeight) <= 1 ? max(leftHeight, rightHeight) + 1 : -1;
    }
};

int main() {
	return 0;
}