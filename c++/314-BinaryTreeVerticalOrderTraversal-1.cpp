#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Using BFS + TreeMap, time complexity O(NlogN)
class Solution {
public:
    vector<vector<int> > verticalOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (root == nullptr) return res;
        
        map<int, vector<int> > columns;
        queue<std::pair<TreeNode*, int> > nodes;
        nodes.push(std::make_pair(root, 0));
        while (!nodes.empty()) {
            TreeNode* node = nodes.front().first;
            int key = nodes.front().second;
            nodes.pop();
            columns[key].push_back(node->val);
            if (node->left != nullptr) {
                nodes.push(std::make_pair(node->left, key - 1));
            }
            if (node->right != nullptr) {
                nodes.push(std::make_pair(node->right, key + 1));
            }
        }
        
        for (auto iter = columns.begin(); iter != columns.end(); iter++) {
            res.push_back(iter->second);
        }
        
        return res;
    }
};

int main() {
  return 0;
}
