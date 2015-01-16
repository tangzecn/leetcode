#include<iostream>
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
    int maxPathSum(TreeNode *root) {
        long long ans = INT_MIN;
        getMaxPathSum(root, ans);
        return ans;
    }
    
    long long getMaxPathSum(TreeNode *root, long long &ans) {
        if (root == NULL) {
            return 0;
        }
        long long maxLeftPathSum = getMaxPathSum(root->left, ans);
        long long maxRightPathSum = getMaxPathSum(root->right, ans);
        ans = max(ans, root->val + maxLeftPathSum + maxRightPathSum);
        return max(0LL, (long long)root->val + max(maxLeftPathSum, maxRightPathSum));
    }
};

int main() {
	return 0;
}
