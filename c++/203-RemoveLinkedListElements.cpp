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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *fakeNode = new ListNode(0);
        fakeNode->next = head;
        ListNode *prevNode = fakeNode, *currNode = head;
        while (currNode != NULL) {
            if (currNode->val == val) {
                prevNode->next = currNode->next;
                delete currNode;
                currNode = prevNode->next;
            } else {
                prevNode = currNode;
                currNode = currNode->next;
            }
        }
        head = fakeNode->next;
        delete fakeNode;
        return head;
    }
};

int main() {
    return 0;
}
