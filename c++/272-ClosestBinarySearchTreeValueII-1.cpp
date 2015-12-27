#include<iostream>
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
    // recursive version, time complexity O(logN + K)
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        // pre stores the closest k values which is not larger than target
	vector<int> pre;
        closestKValues(root, target, k, pre, true);
        // suc stores the closest k values which is larger than target
        vector<int> suc;
        closestKValues(root, target, k, suc, false);
        
        vector<int> res;
        int ptr_p = 0, ptr_s = 0;
        while (res.size() < k && (ptr_p < pre.size() || ptr_s < suc.size())) {
            if (ptr_s >= suc.size() || 
                (ptr_p < pre.size() && target - pre[ptr_p] < suc[ptr_s] - target)) {
                res.push_back(pre[ptr_p++]);    
            } else {
                res.push_back(suc[ptr_s++]);
            }
        }
        return res;
    }
    
private:
    void closestKValues(TreeNode *node, double target, int k, vector<int> &values, bool is_pre) {
        if (node == nullptr || values.size() >= k) return;
        
        if (node->val == target) {
            if (is_pre) {
                if (values.size() < k) {
                    values.push_back(node->val);
                }
                closestKValues(node->left, target, k, values, is_pre);
                closestKValues(node->right, target, k, values, is_pre);
            } else {
                closestKValues(node->right, target, k, values, is_pre);
                closestKValues(node->left, target, k, values, is_pre);
            }
        } else if (node->val < target) {
            if (is_pre) {
                closestKValues(node->right, target, k, values, is_pre);
                if (values.size() < k) {
                    values.push_back(node->val);
                }
                closestKValues(node->left, target, k, values, is_pre);
            } else {
                closestKValues(node->right, target, k, values, is_pre);
            }
        } else {
            if (is_pre) {
                closestKValues(node->left, target, k, values, is_pre);
            } else {
                closestKValues(node->left, target, k, values, is_pre);
                if (values.size() < k) {
                    values.push_back(node->val);
                }
                closestKValues(node->right, target, k, values, is_pre);
            }
        }
    }
};

int main() {
    return 0;
}
