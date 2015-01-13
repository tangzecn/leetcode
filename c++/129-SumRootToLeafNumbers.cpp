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
    int sumNumbers(TreeNode *root) {
        return getSum(root, 0);
    }
    
    long long getSum(TreeNode *root, long long currentNum) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) {
            return currentNum * 10 + root->val;
        }
        return getSum(root->left, currentNum * 10 + root->val) +
            getSum(root->right, currentNum * 10 + root->val);
    }
};

int main() {
	return 0;
}