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
    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0 || head == NULL) return head;
        
        ListNode *fakeNode = new ListNode(0);
        fakeNode->next = head;
        
        int n = 0;
        ListNode *currp = head;
        while (currp != NULL) {
            n++;
            currp = currp->next;
        }
        k = k % n;
        if (k == 0) return head;
        
        currp = fakeNode;
        for (int i=0; i<k; i++) {
            currp = currp->next;
        }
        
        ListNode *prevp = fakeNode;
        while (currp->next != NULL) {
            prevp = prevp->next;
            currp = currp->next;
        }
        fakeNode->next = prevp->next;
        prevp->next = NULL;
        currp->next = head;
        
        head = fakeNode->next;
        delete fakeNode;
        return head;
    }
};

int main() {
	return 0;
}