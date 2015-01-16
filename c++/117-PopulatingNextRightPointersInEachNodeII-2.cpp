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
        TreeLinkNode *preHead = root;
        TreeLinkNode *currentHead = NULL;
        while (preHead != NULL) {
            TreeLinkNode *preLink = preHead;
            TreeLinkNode *currentLink = NULL;
            while (preLink != NULL) {
                if (preLink->left != NULL) {
                    if (currentHead == NULL) {
                        currentHead = preLink->left;
                    } else {
                        currentLink->next = preLink->left;
                    }
                    currentLink = preLink->left;
                }
                if (preLink->right != NULL) {
                    if (currentHead == NULL) {
                        currentHead = preLink->right;
                    } else {
                        currentLink->next = preLink->right;
                    }
                    currentLink = preLink->right;
                }
                preLink = preLink->next;
            }
            preHead = currentHead;
            currentHead = NULL;
        }
    }
};

int main() {
	return 0;
}