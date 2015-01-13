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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        
        ListNode *fastNode = head, *slowNode = head;
        while (fastNode != NULL) {
            slowNode = slowNode->next;
            fastNode = fastNode->next;
            if (fastNode != NULL) {
                fastNode = fastNode->next;
            }
            if (fastNode != NULL && fastNode == slowNode) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {
	return 0;
}