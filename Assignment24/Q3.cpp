#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;
    int n = nums.size();

    for (int num : nums) {
        freq[num]++;

        if (freq[num] > n / 2) {
            return num;
        }
    }

    return -1;  // Majority element doesn't exist (will not be reached for the given constraints)
}

int main() {
    vector<int> nums1 = {3, 2, 3};
    cout << majorityElement(nums1) << endl;  // Output: 3

    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(nums2) << endl;  // Output: 2

    return 0;
}

