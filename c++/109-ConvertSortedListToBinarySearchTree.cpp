#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0;
        ListNode *index = head;
        while (index != NULL) {
            n++; 
            index = index->next;
        }
        index = head;
        return sortedListToBST(index, 0, n - 1);
    }
    
    TreeNode *sortedListToBST(ListNode* &index, int start, int end) {
        if (start > end) return NULL;
        int mid = (start + end) >> 1;
        TreeNode *newNode = new TreeNode(0);
        newNode->left = sortedListToBST(index, start, mid - 1);
        newNode->val = index->val;
        index = index->next;
        newNode->right = sortedListToBST(index, mid + 1, end);
        return newNode;
    }
};

int main() {
	return 0;
}