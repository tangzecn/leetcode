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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        dfs(0, root, ans);
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void dfs(const int level, const TreeNode *root, vector<vector<int> > &ans) {
        if (root == NULL) return;
        if (level >= ans.size()) {
            vector<int> newLevel;
            newLevel.push_back(root->val);
            ans.push_back(newLevel);
        } else {
            ans[level].push_back(root->val);
        }
        dfs(level + 1, root->left, ans);
        dfs(level + 1, root->right, ans);
    }
};

int main() {
	return 0;
}