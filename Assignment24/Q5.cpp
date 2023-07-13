
#include <iostream>
#include <vector>
using namespace std;

int nthUglyNumber(int n) {
    vector<int> ugly(n);
    ugly[0] = 1;

    int idx2 = 0, idx3 = 0, idx5 = 0;
    int nextMultipleOf2 = 2, nextMultipleOf3 = 3, nextMultipleOf5 = 5;

    for (int i = 1; i < n; ++i) {
        int nextUgly = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
        ugly[i] = nextUgly;

        if (nextUgly == nextMultipleOf2) {
            ++idx2;
            nextMultipleOf2 = ugly[idx2] * 2;
        }

        if (nextUgly == nextMultipleOf3) {
            ++idx3;
            nextMultipleOf3 = ugly[idx3] * 3;
        }

        if (nextUgly == nextMultipleOf5) {
            ++idx5;
            nextMultipleOf5 = ugly[idx5] * 5;
        }
    }

    return ugly[n - 1];
}

int main() {
    int n = 10;
    int result = nthUglyNumber(n);

    cout << "The " << n << "th ugly number is: " << result << endl;

    return 0;
}
