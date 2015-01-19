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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *prevNode = NULL, *currentNode = head, *nextNode;
        for (int i=1; i<m; i++) {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        
        ListNode *prevReverse = prevNode, *originalFirstNode = currentNode;
        prevNode = NULL;
        for (int i=m; i<=n; i++) {
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        if (prevReverse == NULL) {
            head = prevNode;
        } else {
            prevReverse->next = prevNode;
        }
        originalFirstNode->next = currentNode;
        return head;
    }
};

int main() {
	return 0;
}