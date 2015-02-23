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
        if (head == NULL) return NULL;
            
        int n = 1;
        ListNode *currp = head;
        while (currp->next != NULL) {
            n++;
            currp = currp->next;
        }
        currp->next = head;
         
        k %= n;
        currp = head;
        for (int i=n-k-1; i>0; i--) {
            currp = currp->next;
        }
        head = currp->next;
        currp->next = NULL;
        
        return head;
    }
};

int main() {
	return 0;
}