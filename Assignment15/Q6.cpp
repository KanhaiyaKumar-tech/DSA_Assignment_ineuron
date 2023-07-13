
#include <iostream>
#include <stack>
#include <string>

int evaluatePostfix(const std::string& S) {
    std::stack<int> st;

    for (char c : S) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();

            int result;
            if (c == '+') {
                result = operand1 + operand2;
            } else if (c == '-') {
                result = operand1 - operand2;
            } else if (c == '*') {
                result = operand1 * operand2;
            } else if (c == '/') {
                result = operand1 / operand2;
            }

            st.push(result);
        }
    }

    return st.top();
}

int main() {
    std::string S = "231*+9-";
    int result = evaluatePostfix(S);
    std::cout << result << std::endl;  // Output: -4


    S = "123+*8-";
    result = evaluatePostfix(S);
    std::cout << result << std::endl;  // Output: -3



    return 0;
}
