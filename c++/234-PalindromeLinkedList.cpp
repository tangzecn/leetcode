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
    bool isPalindrome(ListNode* head) {
        int n = getNodeAmount(head);
        if (n <= 1) return true;
        
        ListNode *head1, *head2;
        cutAndReverse(head, head1, head2, n / 2);
        
        return compareList(head1, (n & 1) ? head2->next : head2);
    }
    
    int getNodeAmount(ListNode* head) {
        ListNode *currp = head;
        int n = 0;
        while (currp != NULL) {
            n++;
            currp = currp->next;
        }
        return n;
    }
    
    void cutAndReverse(ListNode *head, ListNode *&head1, ListNode *&head2, int n) {
        ListNode *lastp = NULL, *currp = head, *nextp;
        for (int i=0; i<n; i++) {
            nextp = currp->next;
            currp->next = lastp;
            lastp = currp;
            currp = nextp;
        }
        head1 = lastp; head2 = currp;
    }
    
    bool compareList(ListNode *head1, ListNode *head2) {
        ListNode *currp1 = head1, *currp2 = head2;
        while (currp1 != NULL || currp2 != NULL) {
            if (currp1 == NULL xor currp2 == NULL) return false;
            if (currp1->val != currp2->val) return false;
            currp1 = currp1->next;
            currp2 = currp2->next;
        }
        return true;
    }
};

int main() {
    return 0;
}
