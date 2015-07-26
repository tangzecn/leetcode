#include<iostream>
#include<stack>
#include<queue>
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
    // Non recursive DFS
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        
        stack<TreeNode*> nodes;
        stack<int> depth;
        nodes.push(root);
        depth.push(1);
        while (!nodes.empty()) {
            int currDepth = depth.top();
            TreeNode *currNode = nodes.top();
            depth.pop();
            nodes.pop();
            if (currDepth > ans.size()) {
                ans.push_back(currNode->val);
            }
            if (currNode->left != NULL) {
                nodes.push(currNode->left);
                depth.push(currDepth + 1);
            }
            if (currNode->right != NULL) {
                nodes.push(currNode->right);
                depth.push(currDepth + 1);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
