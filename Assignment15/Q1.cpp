#include <iostream>
#include <stack>
#include <vector>

std::vector<int> findNextGreater(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> result(n, -1);
    std::stack<int> st;

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = st.top();
        }

        st.push(arr[i]);
    }

    return result;
}

int main() {
    std::vector<int> arr1 = {1, 3, 2, 4};
    std::vector<int> output1 = findNextGreater(arr1);
    std::cout << "Output : ";
    for (int val : output1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr2 = {6, 8, 0, 1, 3};
    std::vector<int> output2 = findNextGreater(arr2);
    std::cout << "Output : ";
    for (int val : output2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

