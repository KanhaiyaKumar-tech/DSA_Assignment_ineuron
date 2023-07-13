
#include <iostream>
#include <vector>

int trapWater(const std::vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int leftMax = 0;
    int rightMax = 0;
    int totalWater = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            leftMax = std::max(leftMax, height[left]);
            totalWater += leftMax - height[left];
            left++;
        } else {
            rightMax = std::max(rightMax, height[right]);
            totalWater += rightMax - height[right];
            right--;
        }
    }

    return totalWater;
}

int main() {
    std::vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int water1 = trapWater(height1);
    std::cout << water1 << std::endl;  // Output: 6

    std::vector<int> height2 = {4, 2, 0, 3, 2, 5};
    int water2 = trapWater(height2);
    std::cout << water2 << std::endl;  // Output: 9

    return 0;
}
