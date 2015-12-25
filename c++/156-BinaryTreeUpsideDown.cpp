#include<iostream>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == nullptr) return root;
        TreeNode *prev_l = root;
        TreeNode *curr_l = prev_l->left, *curr_r = prev_l->right;
        prev_l->left = nullptr; prev_l->right = nullptr;
        while (curr_l != nullptr) {
            TreeNode *next_l = curr_l->left;
            curr_l->left = curr_r;
            TreeNode *next_r = curr_l->right;
            curr_l->right = prev_l;
            
            prev_l = curr_l; 
            curr_l = next_l;
            curr_r = next_r;
        }
        return prev_l;
    }
};

int main() {
    return 0;
}
