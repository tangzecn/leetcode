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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        
        ListNode *odd = head, *even = head->next, *evenHead = even;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        
        return head;
    }
};

int main() {
    return 0;
}
