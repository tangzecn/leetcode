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
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL) return;
        ListNode *slowp = head, *fastp = head->next;
        while (fastp != NULL && fastp->next != NULL) {
            fastp = fastp->next->next;
            slowp = slowp->next;
        }
        
        ListNode *head2 = reverseList(slowp->next);
        slowp->next = NULL;
        
        ListNode *current1 = head, *current2 = head2, *next1, *next2;
        while (current1 != NULL && current2 != NULL) {
            next1 = current1->next;
            next2 = current2->next;
            current1->next = current2;
            current2->next = next1;
            current1 = next1;
            current2 = next2;
        }
    }
    
    ListNode* reverseList(ListNode *head) {
        ListNode *prevp = NULL, *currentp = head, *nextp;
        while (currentp != NULL) {
            nextp = currentp->next;
            currentp->next = prevp;
            prevp = currentp;
            currentp = nextp;
        }
        return prevp;
    }
};

int main() {
	return 0;
}