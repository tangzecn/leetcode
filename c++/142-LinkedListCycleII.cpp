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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        
        ListNode *fastNode = head, *slowNode = head;
        while (fastNode != NULL) {
            slowNode = slowNode->next;
            fastNode = fastNode->next;
            if (fastNode != NULL) {
                fastNode = fastNode->next;
            }
            if (fastNode != NULL && fastNode == slowNode) break;
        }
        if (fastNode == NULL) return NULL;
        
        slowNode = head;
        while (slowNode != fastNode) {
            slowNode = slowNode->next;
            fastNode = fastNode->next;
        }
        return fastNode;
    }
};

int main() {
	return 0;
}