#include <iostream>
#include <stack>

void insertAtBottom(std::stack<int>& st, int item) {
    if (st.empty()) {
        st.push(item);
    } else {
        int temp = st.top();
        st.pop();
        insertAtBottom(st, item);
        st.push(temp);
    }
}

void reverseStack(std::stack<int>& st) {
    if (st.size() > 1) {
        int topElement = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, topElement);
    }
}

int main() {
    std::stack<int> St;

    St.push(3);
    St.push(2);
    St.push(1);
    St.push(7);
    St.push(6);

    reverseStack(St);

    std::cout << "Output: ";
    while (!St.empty()) {
        std::cout << St.top() << " ";
        St.pop();
    }
    std::cout << std::endl;

    std::stack<int> St2;

    St2.push(4);
    St2.push(3);
    St2.push(9);
    St2.push(6);

    reverseStack(St2);

    std::cout << "Output: ";
    while (!St2.empty()) {
        std::cout << St2.top() << " ";
        St2.pop();
    }
    std::cout << std::endl;

    return 0;
}

