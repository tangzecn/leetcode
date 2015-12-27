#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Assume there every value in the tree is unique, 
    // non-recursive version, time complexity O(logN + K)
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> pred, succ;
        initPathStack(root, target, pred, true);
        initPathStack(root, target, succ, false);
        if (!pred.empty() && !succ.empty() && pred.top() == succ.top()) {
            getNext(pred, true);
        }
        vector<int> res;
        while (res.size() < k && (!pred.empty() || !succ.empty())) {
            if (succ.empty() || 
                (!pred.empty() && target - pred.top()->val < succ.top()->val - target)) {
                res.push_back(getNext(pred, true));
            } else {
                res.push_back(getNext(succ, false));
            }
        }
        return res;
    }
    
private:
    void initPathStack(TreeNode *root, double target, stack<TreeNode*> &path, bool is_pred) {
        TreeNode *node = root;
        while (node != nullptr) {
            if (node->val == target) {
                path.push(node);
                break;
            } else if (is_pred) {
                if (node->val < target) {
                    path.push(node);
                    node = node->right;
                } else {
                    node = node->left;
                }
            } else {
                if (node->val < target) {
                    node = node->right;
                } else {
                    path.push(node);
                    node = node->left;
                }
            }
        }
    }
    
    int getNext(stack<TreeNode*> &path, bool is_pred) {
        int ret = path.top()->val;
        TreeNode *node = is_pred ? path.top()->left : path.top()->right;
        path.pop();
        while (node != nullptr) {
            path.push(node);
            node = is_pred ? node->right : node->left;
        }
        return ret;
    }
};

int main() {
    return 0;
}
