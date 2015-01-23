#include<iostream>
#include<climits>
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
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);    
    }
    
    bool isValidBST(TreeNode *root, long long minLimit, long long maxLimit) {
        if (root == NULL) {
            return true;
        }
        if ((long long)root->val <= minLimit || (long long)root->val >= maxLimit) return false;
        return isValidBST(root->left, minLimit, (long long)root->val) &&
            isValidBST(root->right, (long long)root->val, maxLimit);
    }
};

int main() {
	return 0;
}