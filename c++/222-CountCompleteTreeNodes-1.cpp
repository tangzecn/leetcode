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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL) return 1;
        
        int h = 0;
        TreeNode *currNode = root;
        while (currNode->left != NULL) {
            h++;
            currNode = currNode->left;
        }
        
        long long left = 0, right = ((long long)1 << h) - 1;
        while (left < right) {
            long long mid = (left + right + 1) >> 1;
            currNode = root;
            for (int i = h - 1; i>=0; i--) {
                if (mid & ((long long)1 << i)) {
                    currNode = currNode->right;
                } else {
                    currNode = currNode->left;
                } 
            }
            if (currNode != NULL) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return ((long long)1 << h) + left;
    }
};

int main() {
    return 0;
}