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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *prev = NULL, *candidate = head, *tail = head;
        for (int i=0; i<n; i++)
            tail = tail->next;
        while (tail != NULL) {
            prev = candidate;
            candidate = candidate->next;
            tail = tail->next;
        }
        if (prev == NULL) {
            head = candidate->next;
        } else {
            prev->next = candidate->next;
        }
        delete candidate;
        return head;
    }
};

int main() {
	return 0;
}