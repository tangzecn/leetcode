#include<iostream>
#include<vector>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) return res;
        
        binaryTreePaths(root, res, std::to_string(root->val));
        return res;
    }

private:
    void binaryTreePaths(TreeNode *node, vector<string> &res, string solution) {
        if (node->left == nullptr && node->right == nullptr) {
            res.push_back(solution);
        } else {
            if (node->left != nullptr) {
                binaryTreePaths(node->left, res, solution + "->"  + std::to_string(node->left->val));
            }
            if (node->right != nullptr) {
                binaryTreePaths(node->right, res, solution + "->"  + std::to_string(node->right->val));
            }
        }
    }
};

int main() {
    return 0;
}
