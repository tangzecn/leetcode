#include<iostream>
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *root = NULL;
        int n = preorder.size();
        if (n <= 0) return root;
        root = buildTree(preorder, 0, n - 1, inorder, 0, n - 1);
        return root;
    }
    
    TreeNode *buildTree(const vector<int> &preorder, const int startPreorder, const int endPreorder, 
        const vector<int> &inorder, const int startInorder, const int endInorder) {
        if (startPreorder > endPreorder) {
            return NULL;
        }    
        TreeNode *root = new TreeNode(preorder[startPreorder]);
        int indexInorder = startInorder;
        while (indexInorder <= endInorder && inorder[indexInorder] != preorder[startPreorder]) {
            indexInorder++;
        }
        root->left = buildTree(preorder, startPreorder + 1, startPreorder + indexInorder - startInorder, 
            inorder, startInorder, indexInorder - 1);
        root->right = buildTree(preorder, startPreorder + indexInorder - startInorder + 1, endPreorder, 
            inorder, indexInorder + 1, endInorder);
        return root;
    }
};

int main() {
	return 0;
}