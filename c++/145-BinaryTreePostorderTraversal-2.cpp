#include<iostream>
#include<vector>
#include<stack>
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        TreeNode *fakeNode = new TreeNode(0);
        fakeNode->left = root;
        TreeNode *curr = fakeNode, *prev = NULL;
        while (curr != NULL) {
            if (curr->left == NULL) {
                curr = curr->right;
            } else {
                prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    getReverse(ans, curr->left, prev);
                    curr = curr->right;
                }
            }
        }
        
        delete fakeNode;
        return ans;
    }
    
    void getReverse(vector<int> &ans, TreeNode *from, TreeNode *to) {
        reverse(from, to);
        TreeNode *curr = to;
        while (curr != NULL) {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        reverse(to, from);
    }
    
    void reverse(TreeNode *from, TreeNode *to) {
        TreeNode *prev = NULL, *curr = from, *next = NULL;
        while (curr != NULL) {
            next = curr->right;
            curr->right = prev;
            prev = curr;
            curr = next;
        }
    }
};

int main() {
	return 0;
}