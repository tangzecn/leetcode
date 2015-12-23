#include<cmath>
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
    int closestValue(TreeNode* root, double target) {
        if (root == NULL) return INT_MAX;
        
        int res = root->val;
        if (target < root->val && root->left != nullptr) {
            int leftRes = closestValue(root->left, target);
            if (abs((double)leftRes - target) < abs((double)res - target)) {
                res = leftRes;
            }
        } else if (target > root->val && root->right != nullptr) {
            int rightRes = closestValue(root->right, target);
            if (abs((double)rightRes - target) < abs((double)res - target)) {
                res = rightRes;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
