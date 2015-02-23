#include<iostream>
#include<vector>
#include<stack>
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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> nodes;
        vector<int> ans;
        if (root != NULL) {
            nodes.push(root);
            TreeNode *prevTraversal = NULL;
            while (!nodes.empty()) {
                TreeNode *node = nodes.top();
                if ((node->left == NULL && node->right == NULL) ||
                    (node->right != NULL && prevTraversal == node->right) ||
                    (node->left != NULL && node->right == NULL && prevTraversal == node->left)) {
                    ans.push_back(node->val);
                    nodes.pop();
                    prevTraversal = node;        
                } else {
                    if (node->right != NULL) nodes.push(node->right);
                    if (node->left != NULL) nodes.push(node->left);
                }
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}