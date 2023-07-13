
#include <iostream>
#include <stack>
#include <string>

std::string reverseString(const std::string& S) {
    std::stack<char> st;
    for (char c : S) {
        st.push(c);
    }

    std::string reversed_string;
    while (!st.empty()) {
        reversed_string += st.top();
        st.pop();
    }

    return reversed_string;
}

int main() {
    std::string S = "GeeksforGeeks";
    std::string reversed_S = reverseString(S);
    std::cout << reversed_S << std::endl;  // Output: skeeGrofskeeG

    return 0;
}
