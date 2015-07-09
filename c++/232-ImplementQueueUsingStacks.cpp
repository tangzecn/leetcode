#include<iostream>
#include<stack>
using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        dumpStack(s1, s2);
        if (!s2.empty()) s2.pop();
    }

    // Get the front element.
    int peek(void) {
        dumpStack(s1, s2);
        if (!s2.empty()) return s2.top();
	return -1;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }

private: 
    stack<int> s1, s2;
    
    void dumpStack(stack<int> &from, stack<int> &to) {
        if (to.empty()) {
            while (!from.empty()) {
                to.push(from.top());
                from.pop();
            }
        }
    }
};

int main() {
   return 0;
}
