#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        int rectangle, length;
        cin >> rectangle >> length;

        const int del = length / (rectangle + 1);
        const int mod = length % (rectangle + 1);

        const int sum = (rectangle + 1 - mod) * del * del + mod * (del + 1) * (del + 1);
        const int result = (length * length - sum) / 2;

        cout << result << endl;
    }

    return 0;
}
