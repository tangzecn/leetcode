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
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *slowp = head, *fastp = head->next;
        while (fastp != NULL && fastp->next != NULL) {
            slowp = slowp->next;
            fastp = fastp->next->next;
        }
        ListNode *head1 = head, *head2 = slowp->next;
        slowp->next = NULL;
        head1 = sortList(head1);
        head2 = sortList(head2);
        
        ListNode *fakeNode = new ListNode(0);
        head = fakeNode;
        ListNode *tail = head, *p1 = head1, *p2 = head2;
        while (p1 != NULL || p2 != NULL) {
            if (p2 == NULL || (p1 != NULL && p1->val <= p2->val)) {
                tail->next = p1; 
                p1 = p1->next;
            } else {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
            tail->next = NULL;
        }
        head = head->next;
        delete fakeNode;
        return head;
    }
};

int main() {
	return 0;
}