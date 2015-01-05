#include<iostream>
#include<stack>
using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    stack<TreeNode*> nodeStack;
    
    BSTIterator(TreeNode *root) {
        addLeftSons(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodeStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        if (nodeStack.empty()) {
            return -1;
        } else {
            TreeNode *node = nodeStack.top();
            nodeStack.pop();
            if (node->right != NULL) {
                addLeftSons(node->right);    
            }
            return node->val;
        }
    }
    
    void addLeftSons(TreeNode *root) {
        TreeNode *current = root;
        while (current != NULL) {
            nodeStack.push(current);
            current = current->left;
        }        
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
 
 int main() {
	return 0;
}
