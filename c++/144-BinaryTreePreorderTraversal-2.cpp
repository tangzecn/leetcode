#include<iostream>
#include<stack>
#include<vector>
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        TreeNode *curr = root, *prev = NULL;
        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    ans.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}