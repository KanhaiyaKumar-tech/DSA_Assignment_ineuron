
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
    // Count the frequency of each word
    unordered_map<string, int> freq;
    for (const string& word : words) {
        freq[word]++;
    }

    // Custom comparator for sorting based on frequency and lexicographical order
    auto cmp = [&](const string& a, const string& b) {
        if (freq[a] == freq[b]) {
            return a < b;
        } else {
            return freq[a] > freq[b];
        }
    };

    // Create a vector of unique words
    vector<string> uniqueWords;
    for (const auto& entry : freq) {
        uniqueWords.push_back(entry.first);
    }

    // Sort the unique words based on the custom comparator
    sort(uniqueWords.begin(), uniqueWords.end(), cmp);

    // Return the top k frequent words
    return vector<string>(uniqueWords.begin(), uniqueWords.begin() + k);
}

int main() {
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    vector<string> result = topKFrequent(words, k);

    cout << "The " << k << " most frequent words are: ";
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
