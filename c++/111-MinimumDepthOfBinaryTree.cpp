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
    int minDepth(TreeNode *root) {
        int ans = 0;
        findMinDepth(root, 1, ans);
        return ans;
    }
    
    void findMinDepth(const TreeNode *root, int depth, int &ans) {
        if (root == NULL) return;
        if (ans > 0 && depth >= ans) return;
        if (root->left == NULL && root->right == NULL) {
            ans = depth;
            return;
        }
        findMinDepth(root->left, depth + 1, ans);
        findMinDepth(root->right, depth + 1, ans);
    }
};

int main() {
	return 0;
}