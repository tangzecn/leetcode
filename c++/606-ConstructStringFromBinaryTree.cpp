#include<iostream>
#include<string>
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
    string tree2str(TreeNode* t) {
        if (t == nullptr) {
            return "";
        } else {
            string res = std::to_string(t->val);
            if (t->left != nullptr || t->right != nullptr) {
                res.append(1, '(');
                res.append(tree2str(t->left));
                res.append(1, ')');
            }
            if (t->right != nullptr) {
                res.append(1, '(');
                res.append(tree2str(t->right));
                res.append(1, ')');                
            }
            return res;
        }
    }
};

int main() {
    return 0;
}
