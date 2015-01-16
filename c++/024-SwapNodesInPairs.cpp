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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *prev = NULL;    
        ListNode *first = head;
        ListNode *second = first->next;
        ListNode *next = second->next;
        head = NULL;
        while (first != NULL && second != NULL) {
            if (prev == NULL) {
                head = second;
            } else {
                prev->next = second;
            }
            second->next = first;
            first->next = next;
            
            prev = first;
            first = next;
            if (first != NULL) second = first->next;
            if (second != NULL) next = second->next;
        }
        return head;
    }
};

int main() {
    return 0;
}
