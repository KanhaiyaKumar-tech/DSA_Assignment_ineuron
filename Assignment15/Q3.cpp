
#include <iostream>
#include <queue>

class Stack {
private:
    std::queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    int pop() {
        if (q1.empty() && q2.empty()) {
            return -1; // Stack is empty
        }

        if (q1.empty()) {
            std::swap(q1, q2);
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int poppedElement = q1.front();
        q1.pop();
        return poppedElement;
    }
};

int main() {
    Stack s;

    s.push(2);
    s.push(3);
    std::cout << s.pop() << std::endl; // Output: 3

    s.push(4);
    std::cout << s.pop() << std::endl; // Output: 4

    Stack s2;
    s2.push(2);
    std::cout << s2.pop() << std::endl; // Output: 2
    std::cout << s2.pop() << std::endl; // Output: -1

    s2.push(3);
    std::cout << s2.pop() << std::endl; // Output: 3

    return 0;
}
