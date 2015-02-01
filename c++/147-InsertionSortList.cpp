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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode *prevCandidate = fakeHead, *candidate = head;
        while (candidate != NULL) {
            ListNode *prev = fakeHead, *current = fakeHead->next;
            while (current != candidate && current->val <= candidate->val) {
                prev = current;
                current = current->next;
            }
            ListNode *nextCandidate = candidate->next;
            if (current != candidate) {
                prev->next = candidate;
                candidate->next = current;
                prevCandidate->next = nextCandidate;
            } else {
                prevCandidate = candidate;
            }
            candidate = nextCandidate;
        }

        head = fakeHead->next;
        fakeHead->next = NULL;
        delete fakeHead;
        return head;
    }
};

int main() {
	return 0;
}