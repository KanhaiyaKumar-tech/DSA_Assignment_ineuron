#include <iostream>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> uniqueChars;
    int maxLength = 0;
    int left = 0;
    int right = 0;

    while (right < s.length()) {
        if (uniqueChars.count(s[right]) == 0) {
            uniqueChars.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
            right++;
        } else {
            uniqueChars.erase(s[left]);
            left++;
        }
    }

    return maxLength;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl;   // Output: 3
    cout << lengthOfLongestSubstring("bbbbb") << endl;      // Output: 1
    cout << lengthOfLongestSubstring("pwwkew") << endl;     // Output: 3

    return 0;
}
