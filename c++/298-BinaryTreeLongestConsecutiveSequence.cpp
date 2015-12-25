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
    int longestConsecutive(TreeNode* root) {
        return countMaxLen(root).second;
    }
    
private:
    // return value pair<x, y>
    // x indicates the max len which contains node root in the given tree
    // y indicates the max len in the given tree
    std::pair<int, int> countMaxLen(TreeNode* root) {
        if (root == nullptr) return std::make_pair(0, 0);
        pair<int, int> res = std::make_pair(1, 1);
        if (root->left != nullptr) {
            pair<int, int> left_res = countMaxLen(root->left);
            if (root->val + 1 == root->left->val) {
                res.first = max(res.first, left_res.first + 1);
            }
            res.second = max(res.second, max(res.first, left_res.second));
        }
        if (root->right != nullptr) {
            pair<int, int> right_res = countMaxLen(root->right);
            if (root->val + 1 == root->right->val) {
                res.first = max(res.first, right_res.first + 1);
            }
            res.second = max(res.second, max(res.first, right_res.second));
        }
        return res;
    }
};

int main() {
    return 0;
}