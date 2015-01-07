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
        ListNode *fakeHead = new ListNode(0);
        fakeHead->next = head;
        
        ListNode *previous = fakeHead, *current = head;
        while (current != NULL) {
            ListNode *nextNode = current->next;
            bool duplicate = false;
            while (nextNode != NULL && nextNode->val == current->val) {
                current->next = nextNode->next;
                delete nextNode;
                nextNode = current->next;
                duplicate = true;
            }
            if (duplicate) {
                previous->next = nextNode;
                delete current;
            } else {
                previous = current;
            }
            current = nextNode;
        }
        
        head = fakeHead->next;
        delete fakeHead;
        return head;
    }
};

int main() {
	return 0;
}