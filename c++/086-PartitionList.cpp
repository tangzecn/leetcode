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
    ListNode *partition(ListNode *head, int x) {
        ListNode *leftHead = NULL, *leftTail = NULL;
        ListNode *rightHead = NULL, *rightTail = NULL;
        ListNode *current = head;
        while (current != NULL) {
            ListNode *newNode = new ListNode(current->val);
            if (current->val < x) {
                if (leftTail == NULL) {
                    leftHead = newNode;
                } else {
                    leftTail->next = newNode;
                }
                leftTail = newNode;
            } else {
                if (rightTail == NULL) {
                    rightHead = newNode;
                } else {
                    rightTail->next = newNode;
                }
                rightTail = newNode;
            }
            current = current->next;
        }
        
        ListNode *newHead = NULL;
        if (leftHead != NULL) {
            newHead = leftHead;
            leftTail->next = rightHead;
        } else {
            newHead = rightHead;
        }
        
        return newHead;
    }
};

int main() {
	return 0;
}