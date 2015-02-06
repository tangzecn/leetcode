#include<iostream>
using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        
        RandomListNode *currentp = head;
        while (currentp != NULL) {
            RandomListNode *newNode = new RandomListNode(currentp->label);
            newNode->next = currentp->next;
            currentp->next = newNode;
            currentp = newNode->next;
        }
        
        currentp = head;
        while (currentp != NULL) {
            currentp->next->random = currentp->random != NULL ? currentp->random->next : NULL;
            currentp = currentp->next->next;
        }
        
        RandomListNode *newHead = head->next;
        currentp = head;
        while (currentp != NULL) {
            RandomListNode *currentNewNode = currentp->next;
            RandomListNode *nextOldNode = currentNewNode->next;
            currentNewNode->next = nextOldNode != NULL ? nextOldNode->next : NULL;
            currentp->next = nextOldNode;
            currentp = nextOldNode;
        }
        return newHead;
    }
};

int main() {
	return 0;
}