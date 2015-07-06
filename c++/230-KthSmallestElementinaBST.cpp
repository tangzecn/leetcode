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
    // If add a field called nNode in Treenode to indicate the
    // amount of nodes in current subtree, the time complexity
    // can be reduced to O(height of BST).
    int kthSmallest(TreeNode* root, int k) {
        int res = find(root, k);
        return (k == 0) ? res : -1; 
    }
    
    int find(TreeNode *root, int &k) {
        if (root != NULL && k > 0) {
            int kth = find(root->left, k);
            if (k == 0) return kth;
            k--;
            if (k == 0) return root->val;
            else return find(root->right, k);
        }
        return -1;
    }
};

int main() {
	return 0;
}
