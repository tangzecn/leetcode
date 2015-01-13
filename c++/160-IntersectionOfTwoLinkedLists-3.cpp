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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        
        ListNode *currentA = headA, *currentB = headB;
        bool switchA = false, switchB = false;
        while (currentA != currentB) {
            currentA = currentA->next;
            if (currentA == NULL && !switchA) {
                switchA = true;
                currentA = headB;
            }
            currentB = currentB->next;
            if (currentB == NULL && !switchB) {
                switchB = true;
                currentB = headA;
            }
        }
        return currentA;
    }
};

int main() {
	return 0;
}