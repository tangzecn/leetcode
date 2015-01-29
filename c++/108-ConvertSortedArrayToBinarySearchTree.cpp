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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size() - 1);    
    }
    
    TreeNode *sortedArrayToBST(const vector<int> &num, const int start, const int end) {
        if (start > end) return NULL;
        int mid = (start + end) >> 1;
        TreeNode *newNode = new TreeNode(num[mid]);
        newNode->left = sortedArrayToBST(num, start, mid - 1);
        newNode->right = sortedArrayToBST(num, mid + 1, end);
        return newNode;
    }
};

int main() {
	return 0;
}