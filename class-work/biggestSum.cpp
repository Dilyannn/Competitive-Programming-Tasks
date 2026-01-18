#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long fact(int x) {
    long long res = 1;
    for (int i = 2; i <= x; i++) res *= i;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<long long> f(31);
    for (int i = 1; i <= 30; i++) f[i] = fact(i);
    long long mx = -1;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] > a[j]) {
                long long val = f[a[i]] / f[a[i] - a[j]];
                if (val > mx) {
                    mx = val;
                    x = a[i];
                    y = a[j];
                }
            }
        }
    }
    cout << x << " " << y;
}
