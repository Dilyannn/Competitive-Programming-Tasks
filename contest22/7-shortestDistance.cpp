#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long double a, b, c, k, n;

    while (cin >> a >> b >> c >> k >> n) {
        long double A = a;
        long double B = b - k;
        long double C = c - n;

        long double D = B * B - 4 * A * C;

        if (D >= 0) {
            cout << 0 << endl;
        } else {
            long double minValue = fabsl(4 * A * C - B * B) / (4 * fabsl(A));

            long double distance = minValue / sqrtl(k * k + 1);

            cout << (long long)floor(distance) << endl;
        }
    }

    return 0;
}