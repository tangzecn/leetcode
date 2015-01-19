#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Compare {
public:
    bool operator() (const ListNode *x, const ListNode *y) const {
        return x->val < y->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> indexQueue;
        for (int i=0; i<lists.size(); i++) {
            if (lists[i] != NULL) {
                indexQueue.push(lists[i]);
            }
        }
        ListNode *head = NULL, *tail = NULL;
        while (!indexQueue.empty()) {
            ListNode *newNode = indexQueue.top();
            indexQueue.pop();
            if (newNode->next != NULL) {
                indexQueue.push(newNode->next);
                newNode->next = NULL;
            }
            if (tail == NULL) {
                head = newNode;
            } else {
                tail->next = newNode;
            }
            tail = newNode;
        }
        return head;
    }
};

int main() {
	return 0;
}
