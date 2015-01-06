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
        ListNode *last = NULL, *current = head;
        while (current != NULL) {
            bool duplicate = false;
            ListNode *nextNode = current->next;
            while (nextNode != NULL && nextNode->val == current->val) {
                current->next = nextNode->next;
                delete nextNode;
                nextNode = current->next;
                duplicate = true;
            }
            if (duplicate) {
                if (last == NULL) {
                    head = nextNode;
                } else {
                    last->next = nextNode;
                }
                delete current;
                current = nextNode;
            } else {
                if (last == NULL) {
                    head = current;
                }
                last = current;
                current = nextNode;
            }
        }
        return head;
    }
};

int main() {
	return 0;
}