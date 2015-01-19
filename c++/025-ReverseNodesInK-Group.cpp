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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1) return head;
        ListNode *prevGroup = NULL, *currentNode = head;
        while (hasGroup(currentNode, k)) {
            ListNode *prevNode = NULL, *nextNode, *originalGroupHead = currentNode;
            for (int i=0; i<k; i++) {
                nextNode = currentNode->next;
                currentNode->next = prevNode;
                prevNode = currentNode;
                currentNode = nextNode;
            }
            if (prevGroup == NULL) {
                head = prevNode;
            } else {
                prevGroup->next = prevNode;
            }
            originalGroupHead->next = currentNode;
            prevGroup = originalGroupHead;
        }
        return head;
    }
    
    bool hasGroup(ListNode *groupHead, const int k) {
        ListNode *currentNode = groupHead;
        for (int i=0; i<k; i++) {
            if (currentNode == NULL) return false;
            currentNode = currentNode->next;
        }
        return true;
    }
};

int main() {
	return 0;
}