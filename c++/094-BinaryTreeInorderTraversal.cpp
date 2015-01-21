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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode*> nodeStack;
        TreeNode *node = root;
        while (node != NULL || !nodeStack.empty()) {
            if (node == NULL) {
                node = nodeStack.top();
                nodeStack.pop();
                ans.push_back(node->val);
                node = node->right;
            } else {
                nodeStack.push(node);
                node = node->left;
            }
        }
        return ans;
    }
};

int main() {
	return 0;  
}