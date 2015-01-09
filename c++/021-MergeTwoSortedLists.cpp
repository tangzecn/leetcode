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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL, *previousNode = NULL;
        ListNode *current1 = l1, *current2 = l2;
        while (current1 != NULL || current2 != NULL) {
            ListNode *newNode = NULL;
            if (current2 == NULL || (current1 != NULL && current1->val <= current2->val)) {
                newNode = current1;
                current1 = current1->next;
            } else {
                newNode = current2;
                current2 = current2->next;
            }
            newNode->next = NULL;
            if (previousNode == NULL) {
                head = newNode;
            } else {
                previousNode->next = newNode;
            }
            previousNode = newNode;
        }
        return head;
    }
};

int main() {
	return 0;
}