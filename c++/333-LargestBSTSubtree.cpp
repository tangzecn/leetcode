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
    int largestBSTSubtree(TreeNode* root) {
        int min_val = INT_MAX, max_val = INT_MIN, res = 0;
        largestBSTSubtree(root, res, min_val, max_val);
        return res;
    }
    
    // return the total node number of this subtree
    int largestBSTSubtree(TreeNode *node, int &res, int &min_val, int &max_val) {
        if (node == nullptr) {
            return 0;
        }
        int l_min_val = INT_MAX, l_max_val = INT_MIN;
        int l_count = largestBSTSubtree(node->left, res, l_min_val, l_max_val);
        int r_min_val = INT_MAX, r_max_val = INT_MIN;
        int r_count = largestBSTSubtree(node->right, res, r_min_val, r_max_val);
        int count = -1;
        if (l_count >= 0 && r_count >= 0 && l_max_val <= node->val && r_min_val >= node->val) {
            count = l_count + r_count + 1;    
        }
        min_val = min(node->val, min(l_min_val, r_min_val));
        max_val = max(node->val, max(l_max_val, r_max_val));
        res = max(res, count);
        return count;
    }
};

int main() {
    return 0;
}
