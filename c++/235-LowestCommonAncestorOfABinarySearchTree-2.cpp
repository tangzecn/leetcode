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
        if (p == NULL || q == NULL) return NULL;
        
        while (root != NULL && root != p && root != q && !(root->val < p->val xor root->val < q->val)) {
            if (root->val < p->val && root->val < q->val) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return root;
    }
};

int main() {
	return 0;
}
