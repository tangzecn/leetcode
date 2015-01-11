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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ans;
        vector<int> path;
        findPaths(root, sum, ans, path);
        return ans;
    }
    
    void findPaths(
        const TreeNode *root,
        const int sum,
        vector<vector<int> > &ans,
        vector<int> &path) {
        if (root == NULL) return;
        
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (sum == root->val) {
                ans.push_back(path);
            }    
        }
        findPaths(root->left, sum - root->val, ans, path);
        findPaths(root->right, sum - root->val, ans, path);
        path.pop_back();
    }
};

int main() {
	return 0;
}