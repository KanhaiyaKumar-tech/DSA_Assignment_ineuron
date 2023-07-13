#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> symbol_values{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;

    for (int i = 0; i < s.length(); i++) {
        if (i < s.length() - 1 && symbol_values[s[i]] < symbol_values[s[i + 1]]) {
            result -= symbol_values[s[i]];
        } else {
            result += symbol_values[s[i]];
        }
    }

    return result;
}

int main() {
    cout << romanToInt("III") << endl;     // Output: 3
    cout << romanToInt("LVIII") << endl;   // Output: 58

    return 0;
}

