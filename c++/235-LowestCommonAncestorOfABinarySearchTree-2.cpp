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
    // If there can be same values in the tree.
    // The time complexity is O(N)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (root == nullptr || root == p || root == q) return root;
       TreeNode *left = nullptr;
       if (root->val >= p->val || root->val >= q->val) {
           left = lowestCommonAncestor(root->left, p, q);
       }
       TreeNode *right = nullptr;
       if (root->val <= p->val || root->val <= q->val) {
           right = lowestCommonAncestor(root->right, p, q);
       }
       if (left != nullptr && right != nullptr) return root;
       return (left != nullptr) ? left : right;
    }
};

int main() {
	return 0;
}
