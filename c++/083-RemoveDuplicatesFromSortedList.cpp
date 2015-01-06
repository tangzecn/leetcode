#include<iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *current = head;
        while (current != NULL) {
            ListNode *nextNode = current->next;
            while (nextNode != NULL && nextNode->val == current->val) {
                current->next = nextNode->next;
                delete nextNode;
                nextNode = current->next;
            }
            current = nextNode;
        }
        return head;
    }
};

int main() {
	return 0;
}