#include <iostream>
#include <stack>
#include <vector>

std::vector<int> findNearestSmaller(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> result(n, -1);
    std::stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top() >= arr[i]) {
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
    std::vector<int> arr1 = {1, 6, 2};
    std::vector<int> output1 = findNearestSmaller(arr1);
    std::cout << "Output : ";
    for (int val : output1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr2 = {1, 5, 0, 3, 4, 5};
    std::vector<int> output2 = findNearestSmaller(arr2);
    std::cout << "Output : ";
    for (int val : output2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

