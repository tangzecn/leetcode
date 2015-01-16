#include<iostream>
using namespace std;

// Definition for binary tree with next pointer.
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        TreeLinkNode *rootLink = root->next;
        TreeLinkNode *cousin = NULL;
        while (rootLink != NULL) {
           if (rootLink->left != NULL) {
               cousin = rootLink->left;
               break;       
           } 
           if (rootLink->right != NULL) {
               cousin = rootLink->right;
               break;
           }
           rootLink = rootLink->next;
        }
        if (root->right != NULL) {
            root->right->next = cousin;
        }
        if (root->left != NULL) {
            root->left->next = (root->right != NULL) ? root->right : cousin;
        }
        connect(root->right);
        connect(root->left);
    }
};

int main() {
	return 0;
}