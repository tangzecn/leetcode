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
        int nA = getListSize(headA);
        int nB = getListSize(headB);
        
        ListNode *currentA = headA;
        ListNode *currentB = headB;
        if (nA > nB) {
            currentA = moveForward(currentA, nA - nB);
        } else {
            currentB = moveForward(currentB, nB - nA);
        }
        
        while (currentA != currentB) {
            currentA = currentA->next;
            currentB = currentB->next;
        }
        return currentA;
    }
    
    int getListSize(ListNode *head) {
        ListNode *current = head;
        int n = 0;
        while (current != NULL) {
            n++;
            current = current->next;
        }
        return n;
    }
    
    ListNode *moveForward(ListNode *currentNode, int step) {
        while (step > 0 && currentNode != NULL) {
            step--;
            currentNode = currentNode->next;
        }
        return currentNode;
    }
};

int main() {
	return 0;
}