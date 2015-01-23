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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        
        vector<TreeNode*> queue;
        queue.push_back(root);
        vector<int> level;
        level.push_back(root->val);
        ans.push_back(level);
        int start = 0, end = queue.size();
        while (start < end) {
            level.clear();
            for (int j=start; j<end; j++) {
                if (queue[j]->left != NULL) {
                    level.push_back(queue[j]->left->val);
                    queue.push_back(queue[j]->left);
                }
                if (queue[j]->right != NULL) {
                    level.push_back(queue[j]->right->val);
                    queue.push_back(queue[j]->right);
                }
            }
            if (level.size() > 0) {
                ans.push_back(level);
            }
            start = end; end = queue.size();
        }
        return ans;
    }
};

int main() {
	return 0;
}