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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        TreeNode *root = NULL;
        int n = inorder.size();
        if (n <= 0) return root;
        root = buildTree(inorder, 0, n - 1, postorder, 0, n - 1);
        return root;
    }
    
    TreeNode *buildTree(const vector<int> &inorder, const int startInorder, const int endInorder, 
        const vector<int> &postorder, const int startPostorder, const int endPostorder) {
        if (startInorder > endInorder) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[endPostorder]);
        int indexInorder = startInorder;
        while (indexInorder <= endInorder && inorder[indexInorder] != postorder[endPostorder]) {
            indexInorder++;
        }
        root->left = buildTree(inorder, startInorder, indexInorder - 1, 
            postorder, startPostorder, startPostorder + indexInorder - startInorder - 1);
        root->right = buildTree(inorder, indexInorder + 1, endInorder, 
            postorder, startPostorder + indexInorder - startInorder, endPostorder - 1);
        return root;
    }
};

int main() {
	return 0;
}