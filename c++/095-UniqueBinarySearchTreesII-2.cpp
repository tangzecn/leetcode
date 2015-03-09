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
    vector<TreeNode *> generateTrees(int n) {
        return *generateTrees(1, n);
    }
    
    vector<TreeNode *> *generateTrees(int start, int end) {
        vector<TreeNode *> *subTrees = new vector<TreeNode *>(0);
        if (start > end) {
            subTrees->push_back(NULL);
        } else {
            for (int i=start; i<=end; i++) {
                vector<TreeNode *> *leftSubTrees = generateTrees(start, i - 1);
                vector<TreeNode *> *rightSubTrees = generateTrees(i + 1, end);
            
                for (int j=0; j<leftSubTrees->size(); j++)
                    for (int k=0; k<rightSubTrees->size(); k++) {
                        TreeNode *node = new TreeNode(i);
                        if (k == 0) {
                            node->left = (*leftSubTrees)[j];
                        } else {
                            node->left = copyTree((*leftSubTrees)[j]);
                        }
                        if (j == 0) {
                            node->right = (*rightSubTrees)[k];
                        } else {
                            node->right = copyTree((*rightSubTrees)[k]);
                        }
                        subTrees->push_back(node);
                    }
                    
                delete leftSubTrees;
                delete rightSubTrees;
            }
        }
        return subTrees;
    }
    
    TreeNode *copyTree(TreeNode *node) {
        if (node == NULL) {
            return NULL;
        } else {
            TreeNode *newNode = new TreeNode(node->val);
            newNode->left = copyTree(node->left);
            newNode->right = copyTree(node->right);
            return newNode;
        }
    }
};

int main() {
	return 0;
}