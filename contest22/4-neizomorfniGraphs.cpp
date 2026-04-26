#include <cmath>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

#define ll long long
using namespace std;

ll factorial(const int n) {
    ll result = 1;
    for (int i = 2; i <= n; i++) result *= i;
    return result;
}

int getEdgeIndex(int a, int b, const int n) {
    if (a > b) swap(a, b);
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i == a && j == b) return index;
            index++;
        }
    }

    return -1;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        const int totalE = n * (n - 1) / 2;
        vector<pair<int, int>> e; // edges

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                e.push_back({i, j});
            }
        }

        vector<int> permutation(n);
        for (int i = 0; i < n; i++) {
            permutation[i] = i;
        }
        ll sum = 0; // ans

        do {
            vector<bool> used(totalE, false); // dp
            vector<int> cycleL; // length of the cycle; after search

            for (int i = 0; i < totalE; i++) {
                if (!used[i]) {
                    int curr = i;
                    int len = 0;

                    while (!used[curr]) {
                        used[curr] = true;
                        len++;

                        const int a = e[curr].first;
                        const int b = e[curr].second;

                        const int newA = permutation[a];
                        const int newB = permutation[b];

                        curr = getEdgeIndex(newA, newB, n);
                        if (curr == -1) break; // Safety check
                    }
                    cycleL.push_back(len);
                }
            }

            vector<long long> dp(m + 1, 0);
            dp[0] = 1;

            for (const int l : cycleL) {
                for (int s = m; s >= l; s--) {
                    dp[s] += dp[s - l];
                }
            }

            sum += dp[m];
        } while (next_permutation(permutation.begin(), permutation.end()));

        cout << sum / factorial(n) << '\n';
    }

    return 0;
}
