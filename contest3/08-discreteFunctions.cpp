#include <iostream>
#include <limits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    if (!(cin >> testCases)) return 0;
    while (testCases--) {
        int n;
        if (!(cin >> n)) break;

        long long minn = 9223372036854775807LL, maxx = -9223372036854775807LL - 1LL;

        for (int i = 0; i < n; i++) {
            long long x; cin >> x;
            if (x < minn) minn = x;
            if (x > maxx) maxx = x;
        }

        if (n > 0) cout << minn << " " << maxx << endl;
    }

    return 0;
}