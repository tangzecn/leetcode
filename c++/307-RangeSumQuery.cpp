#include<iostream>
#include<vector>
using namespace std;

struct TNode {
    int val, low, high;
    TNode *left, *right;
    TNode(int low, int high) {
        this->val = 0;
        this->low = low;
        this->high = high;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class NumArray {
public:
    NumArray(vector<int> &nums) {
        root = constructTree(0, nums.size() - 1, nums);
    }

    void update(int i, int val) {
        if (root == nullptr) return;
        if (i < root->low || i > root->high) return;
        updateTree(root, i, val);
    }

    int sumRange(int i, int j) {
        return queryTree(root, i, j);
    }
    
    ~NumArray() {
        destroyTree(root);    
    }
    
private:
    TNode* root;
    
    TNode *constructTree(int low, int high, const vector<int> &nums) {
        if (low > high) {
            return nullptr;
        } else {
            TNode *node = new TNode(low, high);
            if (low == high) {
                node->val = nums[low];
            } else {
                int mid = getMid(low, high);
                node->left = constructTree(low, mid, nums);
                node->right = constructTree(mid + 1, high, nums);
                node->val = ((node->left != nullptr) ? node->left->val : 0) + 
                            ((node->right != nullptr) ? node->right->val : 0);
            }
            return node;
        }
    }
    
    void updateTree(TNode* node, const int index, const int val) {
        if (node->low == node->high) {
            node->val = val;
        } else {
            int mid = getMid(node->low, node->high);
            if (index <= mid) {
                node->val -= node->left->val;
                updateTree(node->left, index, val);
                node->val += node->left->val;
            } else {
                node->val -= node->right->val;
                updateTree(node->right, index, val);
                node->val += node->right->val;
            }
        }
    }
    
    int queryTree(TNode *node, int low, int high) {
        if (node == nullptr || high < node->low || low > node->high) {
            return 0;
        } else if (low <= node->low && high >= node->high) {
            return node->val;
        } else {
            return queryTree(node->left, low, high) + queryTree(node->right, low, high);
        }
    }
    
    void destroyTree(TNode *node) {
        if (node == nullptr) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
    
    inline int getMid(int low, int high) {
        return low + ((high - low) >> 1);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

int main() {
    return 0;
}