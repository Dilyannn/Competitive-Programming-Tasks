#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases; cin >> testCases;
    while (testCases--) {
        long long A, N;
        cin >> A >> N;

        if (N == 1) { 
            cout << 1 << endl;
            continue;
        }

        A %= N;

        long long x = A;

        if (x == 0) {         
            cout << 1 << endl;
            continue;
        }

        unordered_set<long long> used;
        used.reserve(1 << 20);
        used.insert(x);

        int k = 1;

        while (true) {
            long long nx;
            {
                long long res = 1 % N, base = A % N, exp = x;
                while (exp > 0) {
                    if (exp & 1) res = ((__int128)res * base) % N;
                    base = ((__int128)base * base) % N;
                    exp >>= 1;
                } nx = res;
            } k++;

            if (nx == 0) {
                cout << k << endl;
                break;
            }

            if (used.count(nx)) {
                cout << 0 << endl;
                break;
            }

            used.insert(nx);
            x = nx;
        }
    }

    return 0;
}
