#include<iostream>
#include<stack>
#include<vector>
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode*> nodes;
        if (root != NULL) {
            nodes.push(root);
            while (!nodes.empty()) {
                TreeNode *node = nodes.top();
                nodes.pop();
                ans.push_back(node->val);
                if (node->right != NULL) {
                    nodes.push(node->right);
                }
                if (node->left != NULL) {
                    nodes.push(node->left);
                }
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}