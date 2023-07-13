
#include <iostream>
#include <stack>

class MinStack {
private:
    std::stack<int> dataStack;
    std::stack<int> minStack;

public:
    MinStack() {}

    void push(int val) {
        dataStack.push(val);

        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (dataStack.top() == minStack.top()) {
            minStack.pop();
        }

        dataStack.pop();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << minStack.getMin() << std::endl;  // Output: -3
    minStack.pop();
    std::cout << minStack.top() << std::endl;     // Output: 0
    std::cout << minStack.getMin() << std::endl;  // Output: -2

    return 0;
}
