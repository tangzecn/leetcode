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
private:
    int countHeight(TreeNode *root) {
        TreeNode *currNode = root;
        int height = 0;
        while (currNode != NULL) {
            height++;
            currNode = currNode->left;
        }
        return height;
    }
    
public:
    int countNodes(TreeNode* root) {
        TreeNode *currNode = root;
        int res = 0;
        while (currNode != NULL) {
            int lHeight = countHeight(currNode->left);
            int rHeight = countHeight(currNode->right);
            if (lHeight == rHeight) {
                // ((1 << lHeight) - 1) + (1)
                res += 1 << lHeight;
                currNode = currNode->right;
            } else {
                res += 1 << rHeight;
                // // ((1 << rHeight) - 1) + (1)
                currNode = currNode->left;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}