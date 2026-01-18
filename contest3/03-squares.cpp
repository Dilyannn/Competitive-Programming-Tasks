#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

using i128 = __int128_t;

static void print_i128(i128 x) {
    if (x == 0) {
      cout << 0;
      return;
    }

    if (x < 0) {
      cout << '-';
      x = -x;
    }

    string str;
    while (x > 0) {
        int d = (int)(x % 10);
        str.push_back(char('0' + d));
        x /= 10;
    }

    reverse(str.begin(), str.end());
    cout << str;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases; cin >> testCases;
    while (testCases--) {
        long long n; cin >> n;

        i128 totalU = (i128)n * (n + 1) * (n + 2) / 6; // n(n+1)(n+2)/6
        i128 totalSquares = 0; // k * k
        i128 sumSquaresAll = 0; // sum of sums

        long long kMax = (n + 1) / 2;

        for (long long i = 1; i <= kMax; i++) {
            long long A = n - 2 * i + 2;
            i128 Ai = (i128)A, ki = (i128)i;

            i128 countK = Ai * (Ai + 1) / 2;
            totalSquares += countK;

            i128 S = Ai * Ai * ki
                   + (Ai - ki) * Ai * (Ai - 1) / 2
                   - (Ai - 1) * Ai * (2 * Ai - 1) / 6;

            sumSquaresAll += ki * ki * S;
        }
        i128 ans = totalSquares * totalU - sumSquaresAll;
        print_i128(ans); cout << endl;
    }

    return 0;
}
