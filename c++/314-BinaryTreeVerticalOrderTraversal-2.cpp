#include<iostream>
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

// Using BFS + 2 Vectors, time complexity O(N)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > verticalOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (root == nullptr) return res;
        
        vector<vector<int> > negative, non_negative;
        queue<std::pair<TreeNode*, int> > nodes;
        nodes.push(std::make_pair(root, 0));
        while (!nodes.empty()) {
            TreeNode* node = nodes.front().first;
            int key = nodes.front().second;
            nodes.pop();

            if (key < 0) {
                if (negative.size() < abs(key)) negative.push_back(vector<int>());
                negative[abs(key+1)].push_back(node->val);
            } else {
                if (non_negative.size() < key + 1) non_negative.push_back(vector<int>());
                non_negative[key].push_back(node->val);
            }

            if (node->left != nullptr) {
                nodes.push(std::make_pair(node->left, key - 1));
            }
            if (node->right != nullptr) {
                nodes.push(std::make_pair(node->right, key + 1));
            }
        }
        
        for (int i=negative.size()-1; i>=0; i--) {
            res.push_back(negative[i]);
        }
        for (int i=0; i<non_negative.size(); i++) {
            res.push_back(non_negative[i]);
        }
        
        return res;
    }
};

int main() {
  return 0;
}
