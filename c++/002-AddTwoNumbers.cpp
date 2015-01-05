#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      ListNode *head = NULL, *current = NULL, *last = NULL;
      int x0 = 0;
      while (l1 != NULL || l2 != NULL || x0 != 0) {
        current = new ListNode(x0);
        if (l1 != NULL) current->val += l1->val;
        if (l2 != NULL) current->val += l2->val;
        x0 = current->val / 10;
        current->val %= 10;

        if (last == NULL) {
            head = current; last = current;
        } else {
            last->next = current; last = current;
        }
        
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
      }    
      return head;
    }
};

int main() {
    return 0;
}
