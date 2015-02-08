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
        ListNode *fakeNode = new ListNode(0);
        fakeNode->next = head;
        head = fakeNode;
        
        int groupSize = 1, mergeCount;
        do {
            mergeCount = 0;
            ListNode *prevp = head, *currp = head->next;
            while (currp != NULL) {
                ListNode *prevGroup1 = prevp, *groupHead1 = currp;
                goForward(prevp, currp, groupSize);
                if (currp == NULL) break;
                ListNode *prevGroup2 = prevp, *groupHead2 = currp;
                goForward(prevp, currp, groupSize);
                
                mergeCount++;
                prevGroup2->next = NULL; prevp->next = NULL;
                ListNode *mergedHead, *mergedTail;
                mergeGroup(mergedHead, mergedTail, groupHead1, groupHead2);
                prevGroup1->next = mergedHead; 
                mergedTail->next = currp;
                prevp = mergedTail;
            }
            groupSize <<= 1;    
        } while (mergeCount > 0);

        head = fakeNode->next;
        delete fakeNode;
        return head;
    }
    
    void goForward(ListNode *&prevp, ListNode *&currp, int stepNum) {
        while (currp != NULL && stepNum > 0) {
            prevp = currp;
            currp = currp->next;
            stepNum--;
        }
    }
    
    void mergeGroup(ListNode *&head, ListNode *&tail, ListNode *groupHead1, ListNode *groupHead2) {
        ListNode *fakeNode = new ListNode(0);
        tail = fakeNode;
        ListNode *currp1 = groupHead1, *currp2 = groupHead2;
        while (currp1 != NULL || currp2 != NULL) {
            if (currp2 == NULL || (currp1 != NULL && currp1->val <= currp2->val)) {
                tail->next = currp1;
                currp1 = currp1->next;
            } else {
                tail->next = currp2;
                currp2 = currp2->next;
            }
            tail = tail->next;
            tail->next = NULL;
        }
        head = fakeNode->next;
        tail = (tail == fakeNode) ? NULL : tail;
        delete fakeNode;
    }
};

int main() {
	return 0;
}