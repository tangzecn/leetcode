#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    stack<int> value;
    stack<int> minValue;
    
    void push(int x) {
        value.push(x);
        if (minValue.empty() || minValue.top() >= x) 
            minValue.push(x);
    }

    void pop() {
        if (value.empty()) return;
        if (minValue.top() == value.top()) 
          minValue.pop();
        value.pop();
    }

    int top() {
        return value.top();
    }

    int getMin() {
        return minValue.top();
    }
};

int main() {
	return 0;
}