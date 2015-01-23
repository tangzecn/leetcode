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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        dfs(0, root, ans);
        for (int i=0; i<ans.size(); i++) {
            if ((i & 1) == 1) {
                std::reverse(ans[i].begin(), ans[i].end());
            }
        }
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