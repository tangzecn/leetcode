#include<queue>
using namespace std;

class Stack {
private:
    queue<int> q1, q2;
    bool topInQ1;
    
    void dumpQueue(queue<int> &from, queue<int> &to) {
        while (!from.empty()) {
            int x = from.front();
            from.pop();
            if (from.empty()) {
                from.push(x);
                break;
            } else {
                to.push(x);
            }
        }
    }
    
public:
    Stack() {
        topInQ1 = true;
    }

    // Push element x onto stack.
    void push(int x) {
        if (topInQ1) {
            q1.push(x);
        } else {
            q2.push(x);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if (topInQ1) {
            dumpQueue(q1, q2);
            q1.pop();
            topInQ1 = false;
        } else {
            dumpQueue(q2, q1);
            q2.pop();
            topInQ1 = true;
        } 
    }

    // Get the top element.
    int top() {
        if (topInQ1) {
            dumpQueue(q1, q2);
            return q1.front();
        } else {
            dumpQueue(q2, q1);
            return q2.front();
        } 
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();    
    }
};

int main() {
    return 0;
}
